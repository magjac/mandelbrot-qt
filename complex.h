#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
  public:
    Complex() {}
    Complex(double r, double i) {
        re = r;
        im = i;
    }
    double re, im;
    Complex operator + (const Complex& param);
    Complex operator * (const Complex& param);
    double abs ();
};

#endif // COMPLEX_H
