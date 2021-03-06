/* Copyright 2013 Andrey Golodyaev */
#ifndef CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_H_
#define CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_H_

class ComplexNumber {
 public :
    ComplexNumber();
    ComplexNumber(double real, double imaginary);
    ~ComplexNumber();

    double GetReal() const;
    double GetImaginary() const;
    void SetReal(double real);
    void SetImaginary(double imaginary);
    bool Input(const char *str);
    void Output(char* str);
    ComplexNumber operator +(const ComplexNumber &second) const;
    ComplexNumber operator -(const ComplexNumber &second) const;
    ComplexNumber operator *(const ComplexNumber &second) const;
    ComplexNumber operator /(const ComplexNumber &second) const;
    bool operator ==(const ComplexNumber &second) const;
 private :
    double real;
    double imaginary;
};

#endif  // CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_H_
