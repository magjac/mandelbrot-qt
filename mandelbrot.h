#ifndef MAIN
#define MAIN

#include "complex.h"
#include <QObject>
#include <QList>
#include <QRect>
#include <QGraphicsScene>
#include <QPixmap>
#include <QPainter>

class Mandelbrot : public QObject
{
    Q_OBJECT

public:
    Mandelbrot(QGraphicsScene *scene, QPixmap *pixmap, QPainter *painter) {
        m_scene = scene;
        m_pixmap = pixmap;
        m_painter = painter;
        m_height = 1024;
        m_width = 1024;
        m_min = Complex(-2.0, -2.0);
        m_max = Complex(2.0, 2.0);
        m_max_iter = 100;
        m_num_plots = 0;
    }
    void plot();

public slots:
    void set_size(int width, int height);
    void set_boundaries(Complex min, Complex max);
    void set_max_iter(int max_iter);
    void set_center(Complex center);
    void ready(const QList<QRectF> &region);

private:
    QGraphicsScene *m_scene;
    QPixmap *m_pixmap;
    QPainter *m_painter;
    int m_height;
    int m_width;
    Complex m_min;
    Complex m_max;
    int m_max_iter;
    int m_num_plots;
    int iterate(Complex c, int limit);

};

#endif // MAIN
