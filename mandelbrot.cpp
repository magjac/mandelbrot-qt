#include "mandelbrot.h"
#include <iostream>

void Mandelbrot::set_size(int width, int height) {
    m_width = width;
    m_height = height;
}

void Mandelbrot::set_boundaries(Complex min, Complex max) {
    m_min = min;
    m_max = max;
}

void Mandelbrot::set_max_iter(int max_iter) {
    m_max_iter = max_iter;
}

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

void Mandelbrot::plot() {
    for (int ir = 0; ir < m_height; ir++)
    {
        for (int ic = 0; ic < m_width; ic++)
        {
            Complex c (m_min.re + (m_max.re - m_min.re) * ic / m_width, m_min.im + (m_max.im - m_min.im) * ir / m_height);
            int n = iterate(c, m_max_iter);
            QColor color (0, 0, 255 - n * 255 / m_max_iter);
            m_painter->setPen(color);
            m_painter->drawPoint(ic, ir);
        }
    }
}

