#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;


namespace ariel {
class Fraction{

    private: 
        int numerator;
        int denominator;

    public:

    Fraction(int numerator, int denominator);

    Fraction(double number);
    
    void setNumerator(int);
    void setDenominator(int);

    int getNumerator() const;
    int getDenominator() const;
        
    
    // ----------------- Requested functions ---------------------

    Fraction operator+(Fraction& other);

    double operator+(double num);

    Fraction operator-(Fraction& other);

    double operator-(double f);

    Fraction operator*(Fraction& other);

    double operator*(double f);
    
    friend Fraction operator*(double f, const Fraction &frac);
    
    Fraction operator/( Fraction& other);
    
    bool operator==(const Fraction& other) const;
    
    bool operator!=(const Fraction& other) const;
    
    bool operator<(const Fraction& other) const;
    
    bool operator>(const Fraction& other) const;
    
    bool operator<=(const Fraction& other) const;
    
    bool operator>=(const Fraction& other) const;
    
    Fraction& operator++();
    
    Fraction& operator--();
    
    Fraction operator++(int);
    
    Fraction operator--(int);
    
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);

};

    
};

#endif