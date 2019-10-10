#ifndef MAIN
#define MAIN

#include "complex.h"
#include <QObject>
#include <QList>
#include <QRect>
#include <QPainter>

class Mandelbrot : public QObject
{
    Q_OBJECT

public:
    Mandelbrot(QPainter *p) {
        m_painter = p;
        m_height = 1024;
        m_width = 1024;
        m_min = Complex(-2.0, -2.0);
        m_max = Complex(2.0, 2.0);
        m_max_iter = 100;
    }
    void plot();

public slots:
    void set_size(int width, int height);
    void set_boundaries(Complex min, Complex max);
    void set_max_iter(int max_iter);
    void ready(const QList<QRectF> &region);

private:
    QPainter *m_painter;
    int m_height;
    int m_width;
    Complex m_min;
    Complex m_max;
    int m_max_iter;
    int iterate(Complex c, int limit);

};

#endif // MAIN
