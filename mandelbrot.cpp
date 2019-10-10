#include "mandelbrot.h"
#include <iostream>

void Mandelbrot::ready(const QList<QRectF> &region)
{
    std::cout << "READY! " << std::endl;
}

int Mandelbrot::iterate(Complex c, int limit) {
  Complex z (0.0, 0.0);
  int n;
  for (n = 0; n < limit && z.abs() < 2.0; n++) {
    z = z * z + c;
  }
  return n;
}

void Mandelbrot::plot(QPainter *p, int height, int width, Complex min, Complex max, int max_iter) {
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

