#include "mandelbrot.h"
#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <iostream>

int main(int argc, char *argv[])
{
    const Complex min (-2.5, -1.5);
    const Complex max (1.5, 1.5);
    const int image_width = 256;
    const int image_height = image_width * 3 / 4;

    QApplication a(argc, argv);
    QGraphicsScene scene (0, 0, image_width, image_height);
    QGraphicsView view(&scene);
    view.setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view.setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view.show();

    QPixmap pixmap(image_width, image_height);
    QPainter painter(&pixmap);

    Mandelbrot mandelbrot(&a, &scene, &pixmap, &painter);
    mandelbrot.set_image_size(image_width, image_height);
    mandelbrot.set_boundaries(min, max);
    mandelbrot.set_center(Complex(-0.743643887037158704752191506114774, 0.131825904205311970493132056385139));
    QObject::connect(&scene, &QGraphicsScene::changed,
                     &mandelbrot, &Mandelbrot::ready);
    const int max_iter = 255;
    mandelbrot.set_max_iter(max_iter);

    return a.exec();
}
