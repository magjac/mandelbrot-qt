#ifndef MAIN
#define MAIN

#include <QObject>
#include <QList>
#include <QRect>

class Mandelbrot : public QObject
{
    Q_OBJECT

public:
    Mandelbrot() {
    }

public slots:
    void ready(const QList<QRectF> &region);

};

#endif // MAIN

