#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;
namespace ariel {};
using namespace ariel;


class Fraction{

    //All are private by default, wrote this so it's easier to understand
    private: 
        int numerator;
        int denominator;
    
    public:
        //Empty constructor - not default since there's another one
        Fraction();
        // Parametized constructor
        Fraction(int numerator , int denominator);

        void setNumerator(int);
        void setDenominator(int);

        int getNumerator() const;
        int getDenominator() const;
        
        void toString();

        // ----------------- Requested functions ---------------------

        void toReducedForm(); // converts fractions to reduced

        bool isReducedForm(); // makes sure it is in simplest form possible

        Fraction operator-(const Fraction& frc) const;

        Fraction operator+(const Fraction& frc) const;

        Fraction operator*(const Fraction& frc) const;

        Fraction operator/(const Fraction& frc) const;

        Fraction operator++(void);

        Fraction operator--(void);

        bool operator==(const Fraction& frc);

        bool operator!=(const Fraction& frc);

        bool operator<=(const Fraction& frc);

        bool operator>=(const Fraction& frc);

        bool operator<(const Fraction& frc);

        bool operator>(const Fraction& frc);



        friend ostream& operator<< (ostream& ost, const Fraction& frc);

        friend istream& operator>> (istream& ist, Fraction& frc);



        // ----------------- help functions ------------------

        int lcd(int num1, int num2);

        Fraction doubleToFunction(double num);
    

};

#endif