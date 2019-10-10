#include "complex.h"
#include "mandelbrot.h"
#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <iostream>

int iterate(Complex c, int limit) {
  Complex z (0.0, 0.0);
  int n;
  for (n = 0; n < limit && z.abs() < 2.0; n++) {
    z = z * z + c;
  }
  return n;
}

void plot_mandelbrot(QPainter *p, int height, int width, Complex min, Complex max, int max_iter) {
    for (int ir = 0; ir < height; ir++)
    {
        for (int ic = 0; ic < width; ic++)
        {
            Complex c (min.re + (max.re - min.re) * ic / width, min.im + (max.im - min.im) * ir / height);
            int n = iterate(c, max_iter);
            QColor color (0, 0, 255 - n * 255 / max_iter);
            p->setPen(color);
            p->drawPoint(ic, ir);
        }
    }
}

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

    Mandelbrot mandelbrot;
    QObject::connect(&scene, &QGraphicsScene::changed,
                     &mandelbrot, &Mandelbrot::ready);
    const int max_iter = 100;

    plot_mandelbrot(&p, height, width, min, max, max_iter);
    scene.addPixmap(pixmap);

    return a.exec();
}
