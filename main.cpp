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
    const int width = 1024;
    const int height = width * 3 / 4;

    QApplication a(argc, argv);
    QGraphicsScene scene (0, 0, width, height);
    QGraphicsView view(&scene);
    view.show();

    QPixmap pixmap(width, height);
    QPainter p(&pixmap);

    Mandelbrot mandelbrot(&p);
    mandelbrot.set_size(width, height);
    mandelbrot.set_boundaries(min, max);
    QObject::connect(&scene, &QGraphicsScene::changed,
                     &mandelbrot, &Mandelbrot::ready);
    const int max_iter = 100;
    mandelbrot.set_max_iter(max_iter);

    mandelbrot.plot();
    scene.addPixmap(pixmap);

    return a.exec();
}
