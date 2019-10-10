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
    Mandelbrot() {
    }
    void plot(QPainter *p, int height, int width, Complex min, Complex max, int max_iter);

public slots:
    void ready(const QList<QRectF> &region);

private:
    int iterate(Complex c, int limit);

};

#endif // MAIN

