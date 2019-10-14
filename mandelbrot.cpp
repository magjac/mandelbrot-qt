#include <QApplication>
#include "mandelbrot.h"
#include <iostream>

void Mandelbrot::set_image_size(int width, int height) {
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
void Mandelbrot::set_center(Complex center) {
    Complex current_center ((m_min.real() + m_max.real()) / 2.0, (m_min.imag() + m_max.imag()) / 2.0);
    Complex offset = center - current_center;
    m_min = m_min + offset;
    m_max = m_max + offset;
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
    Complex current_center ((m_min.real() + m_max.real()) / 2.0, (m_min.imag() + m_max.imag()) / 2.0);
    m_min.real(current_center.real() - (current_center.real() - m_min.real()) * 0.9);
    m_min.imag(current_center.imag() - (current_center.imag() - m_min.imag()) * 0.9);
    m_max.real(current_center.real() + (m_max.real() - current_center.real()) * 0.9);
    m_max.imag(current_center.imag() + (m_max.imag() - current_center.imag()) * 0.9);
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
    for (int ir = 0; ir < m_height; ir++)
    {
        for (int ic = 0; ic < m_width; ic++)
        {
            Complex c (m_min.real() + (m_max.real() - m_min.real()) * ic / m_width, m_min.imag() + (m_max.imag() - m_min.imag()) * ir / m_height);
            int n = iterate(c, m_max_iter);
            QColor color;
            if (n < m_max_iter && n > 0) {
                color = {m_color_map[n % 16]};
            } else {
                color = Qt::black;
            }
            m_painter->setPen(color);
            m_painter->drawPoint(ic, m_height - 1 - ir);
        }
    }
    m_scene->addPixmap(*m_pixmap);
    m_num_plots++;
}

