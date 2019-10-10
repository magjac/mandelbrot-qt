#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <iostream>
#include <math.h>

class Complex {
  public:
    Complex() {}
    Complex(double r, double i) {
      re = r;
      im = i;
    };
    double re, im;
    Complex operator + (const Complex& param) {
      Complex temp;
      temp.re = re + param.re;
      temp.im = im + param.im;
      return temp;
    }
    Complex operator * (const Complex& param) {
      Complex temp;
      temp.re = re * param.re - im * param.im;
      temp.im = re * param.im + im * param.re;
      return temp;
    }
    double abs () {
      return sqrt(re * re + im * im);
    }
};

int iterate(Complex c, int limit) {
  Complex z (0.0, 0.0);
  int n;
  for (n = 0; n < limit && z.abs() < 2.0; n++) {
    z = z * z + c;
  }
  return n;
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

    const int max_iter = 100;

    for (int ir = 0; ir < height; ir++)
    {
        for (int ic = 0; ic < width; ic++)
        {
            Complex c (min.re + (max.re - min.re) * ic / width, min.im + (max.im - min.im) * ir / height);
            int n = iterate(c, max_iter);
            QColor color (0, 0, 255 - n * 255 / max_iter);
            p.setPen(color);
            p.drawPoint(ic, ir);
        }
    }
    scene.addPixmap(pixmap);
    return a.exec();
}
