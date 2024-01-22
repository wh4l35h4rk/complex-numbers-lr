#include <iostream>
#include <cmath>

double const E = 0.00000000001;

class ComplexNumber{
private:
    double re;
    double im;

public:
    ComplexNumber(double r, double i) : re(r), im(i) {}

    void setRe (double n) { this->re = n; }
    double getRe () { return re; }
    void setIm (double n) { this->im = n; }
    double getIm () { return im; }

    static ComplexNumber addition (const ComplexNumber a, const ComplexNumber b){
        return ComplexNumber(
            a.re + b.re,
            a.im + b.im
        );
    }

    static ComplexNumber substraction (const ComplexNumber minuend, const ComplexNumber subtrahend){
        return ComplexNumber(
            minuend.re - subtrahend.re,
            minuend.im - subtrahend.im
        );
    }

    static ComplexNumber multiplication (const ComplexNumber a, const ComplexNumber b) {
        return ComplexNumber(
            a.re * b.re - a.im * b.im,
            a.re * b.im - b.re * a.im
        );
    }

    static ComplexNumber division (ComplexNumber dividend, ComplexNumber divisor) {
        return ComplexNumber(
            (dividend.re * divisor.re + dividend.im * divisor.im) / (pow(divisor.re, 2) + pow(divisor.im, 2)),
            (divisor.re * dividend.im - dividend.re * divisor.im) / (pow(divisor.re, 2) + pow(divisor.im, 2))
        );
    }

    bool operator== (const ComplexNumber &b) {
        return fabs(re - b.re) < E
            && fabs(im - b.im) < E;
    }

    bool operator!= (const ComplexNumber &b) {
        return !(*this == b);
    }

    bool operator== (const double &b) {
        return fabs(re - b) < E 
            && im < E;
    }

    bool operator!= (const double &b) {
        return !(*this == b);
    }

    double modulus (){
        return sqrt(pow(re, 2) + pow(im, 2));
    }

    double arg (){
        if (re >= 0)
            return atan(im / re);
        else
            return atan(im / re + M_PI);
    }

    ComplexNumber cpow (const int n) {
        return ComplexNumber(
            pow (modulus(), n) *
                cos (n * arg()),
            pow (modulus(), n) *
                sin (n * arg())
        );
    }

    void output () {
        std::string plus = "";
        if (im >= 0) plus = "+";
        std::cout << re << plus << im << "i";
    }
};

int main() {
    ComplexNumber test(2, 5);
    std::cout << "getRe: " << test.getRe() << std::endl;
    std::cout << "getIm: " << test.getIm() << std::endl;

    ComplexNumber test2(0, 0);
    test2.setRe(1);
    test2.setIm(4);
    test2.output();

    std::cout << std::endl << std::endl;
    std::cout << "a: "; test.output();
    std::cout << std::endl << "b: "; test2.output();

    //сложение
    std::cout << std::endl << std::endl;
    ComplexNumber add = ComplexNumber::addition(test, test2);
    std::cout << "add: "; add.output();
    std::cout << std::endl;

    //вычитание
    ComplexNumber sub = ComplexNumber::substraction(test, test2);
    std::cout << "sub: "; sub.output();
    std::cout << std::endl;

    //умножение
    ComplexNumber mul = ComplexNumber::multiplication(test, test2);
    std::cout << "mul: "; mul.output();
    std::cout << std::endl;

    //деление
    ComplexNumber div = ComplexNumber::division(test, test2);
    std::cout << "div: "; div.output();
    std::cout << std::endl << std::endl;

    //модуль и аргумент
    std::cout << "modulus: " << test.modulus() << std::endl;
    std::cout << "argument: " << test.arg();
    std::cout << std::endl << std::endl;

    //сравнение с комплексным числом
    if (test == test2) {
        test.output();
        std::cout << " equals ";
        test2.output(); 
        std::cout << std::endl;
    } else {
        test.output();
        std::cout << " doesn't equal ";
        test2.output(); 
        std::cout << std::endl;
    } 

    //сравнение с действительным числом
    if (test == 2) {
        test.output();
        std::cout << " equals 2" << std::endl;
    } else {
        test.output();
        std::cout << " doesn't equal 2" << std::endl;
    }      

    test.setIm(0);
    if (test == 2) {
        test.output();
        std::cout << " equals 2" << std::endl;
    } else {
        test.output();
        std::cout << " doesn't equal 2" << std::endl;
    }  

    test.setIm(4);
    std::cout << std::endl;

    //возведение в степень
    ComplexNumber pow2 = test.cpow(2);
    std::cout << "pow2: "; pow2.output();
}
