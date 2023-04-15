#include <iostream>
#include "Fraction.hpp"

using namespace std;


Fraction :: Fraction(int numerator , int denominator){
    this -> numerator = numerator;
    this -> denominator = denominator;
}

// ----------- Getters & Setters------------

int Fraction :: getNumerator() const{
    return this -> numerator;
}

int Fraction :: getDenominator() const{
    return this -> denominator;
}

void Fraction :: setNumerator(int numerator){
    this -> numerator = numerator;
}

void Fraction :: setDenominator(int denominator){
    this -> denominator = denominator;
}

// --------------- Requested functions ------------------

bool Fraction :: operator==(const Fraction& frc){
    if (this ->numerator == frc.getNumerator() && this ->denominator == frc.getDenominator()){
        return true;
    }
    return false;
}