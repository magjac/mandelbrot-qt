#include <QApplication>
#include "mandelbrot.h"
#include <iostream>

void Mandelbrot::set_image_size(int width, int height) {
    m_image_width = width;
    m_image_height = height;
}

void Mandelbrot::set_boundaries(Complex min, Complex max) {
    m_center = (min + max ) / 2.0;
    m_size = max - min;
}

void Mandelbrot::set_max_iter(int max_iter) {
    m_max_iter = max_iter;
}
void Mandelbrot::set_center(Complex center) {
    m_center = center;
}

void Mandelbrot::ready(const QList<QRectF> &region)
{
    std::cout << "READY with plot " << m_num_plots << std::endl;
    if (region.size() == 0) {
        return;
    }
    if (m_num_plots == 5) {
        m_app->quit();
        return;
    }
    QCoreApplication::processEvents();
    plot();
    m_size *= 0.9;
}

int Mandelbrot::iterate(Complex c, int limit) {
  Complex z (0.0, 0.0);
  int n;
  for (n = 0; n < limit && norm(z) < 4.0; n++) {
    z = z * z + c;
  }
  return n;
}

void Mandelbrot::plot() {
    for (int ir = 0; ir < m_image_height; ir++)
    {
        for (int ic = 0; ic < m_image_width; ic++)
        {
            Complex c (m_center.real() - m_size.real() / 2.0 + m_size.real() * ic / m_image_width, m_center.imag() - m_size.imag() / 2.0 + m_size.imag() * ir / m_image_height);
            int n = iterate(c, m_max_iter);
            QColor color;
            if (n < m_max_iter && n > 0) {
                color = {m_color_map[n % 16]};
            } else {
                color = Qt::black;
            }
            m_painter->setPen(color);
            m_painter->drawPoint(ic, m_image_height - 1 - ir);
        }
    }
    m_scene->addPixmap(*m_pixmap);
    m_num_plots++;
}

