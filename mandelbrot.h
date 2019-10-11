#ifndef MAIN
#define MAIN

#include <complex>
#include <QObject>
#include <QList>
#include <QRect>
#include <QGraphicsScene>
#include <QPixmap>
#include <QPainter>
#include <QColor>

typedef std::complex<double> Complex;

class Mandelbrot : public QObject
{
    Q_OBJECT

public:
    Mandelbrot(QApplication *app, QGraphicsScene *scene, QPixmap *pixmap, QPainter *painter) {
        m_app = app;
        m_scene = scene;
        m_pixmap = pixmap;
        m_painter = painter;
        m_height = 1024;
        m_width = 1024;
        m_min = Complex(-2.0, -2.0);
        m_max = Complex(2.0, 2.0);
        m_max_iter = 100;
        m_num_plots = 0;
        m_color_map[0].setRgb(66, 30, 15);
        m_color_map[1].setRgb(25, 7, 26);
        m_color_map[2].setRgb(9, 1, 47);
        m_color_map[3].setRgb(4, 4, 73);
        m_color_map[4].setRgb(0, 7, 100);
        m_color_map[5].setRgb(12, 44, 138);
        m_color_map[6].setRgb(24, 82, 177);
        m_color_map[7].setRgb(57, 125, 209);
        m_color_map[8].setRgb(134, 181, 229);
        m_color_map[9].setRgb(211, 236, 248);
        m_color_map[10].setRgb(241, 233, 191);
        m_color_map[11].setRgb(248, 201, 95);
        m_color_map[12].setRgb(255, 170, 0);
        m_color_map[13].setRgb(204, 128, 0);
        m_color_map[14].setRgb(153, 87, 0);
        m_color_map[15].setRgb(106, 52, 3);
    }
    void plot();

public slots:
    void set_size(int width, int height);
    void set_boundaries(Complex min, Complex max);
    void set_max_iter(int max_iter);
    void set_center(Complex center);
    void ready(const QList<QRectF> &region);

private:
    QApplication *m_app;
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
    QColor m_color_map[16];

};

#endif // MAIN
