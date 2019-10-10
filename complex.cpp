#include <math.h>
#include "complex.h"

Complex Complex::operator + (const Complex& param) {
    Complex temp;
    temp.re = re + param.re;
    temp.im = im + param.im;
    return temp;
}

Complex Complex::operator * (const Complex& param) {
    Complex temp;
    temp.re = re * param.re - im * param.im;
    temp.im = re * param.im + im * param.re;
    return temp;
}

double Complex::abs () {
    return sqrt(re * re + im * im);
}
