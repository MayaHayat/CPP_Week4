#include "Fraction.hpp"
#include <iostream>

using namespace std;
namespace ariel{

Fraction :: Fraction(int numerator , int denominator){
    this -> numerator = numerator;
    this -> denominator = denominator;
}

Fraction::Fraction(double numerator) {
    this -> numerator = numerator;
    this -> denominator = 1;
    
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
    if (denominator == 0){
        throw std :: invalid_argument ("This demoninator is illegal");
    }
    this -> denominator = denominator;
}


// --------------- Requested functions ------------------


Fraction Fraction::operator+(Fraction& frc) {
    int nummerator = (numerator * frc.denominator) + (frc.numerator * denominator);
    int denominator = denominator * frc.denominator;
    return Fraction(numerator, denominator);
}


double Fraction::operator+(double num){
    return this->numerator/this->denominator + num;
}

Fraction Fraction::operator-(Fraction& frc) {
    int nummerator = (numerator * frc.denominator) - (frc.numerator * denominator);
    int denominator = denominator * frc.denominator;
    return Fraction(numerator, denominator);
}

double Fraction::operator-(double num){
    return this->numerator/this->denominator - num;
}


Fraction Fraction::operator*( Fraction& frc)  {
    int nummerator = (numerator * frc.denominator) * (frc.numerator * denominator);
    int denominator = denominator * frc.denominator;
    return Fraction(numerator, denominator);
}

double Fraction::operator*(double num){
    
    return this->numerator/this->denominator * num;
}

Fraction operator*(double num, const Fraction &frac){
    
    return Fraction(1,2);
}


Fraction Fraction::operator/( Fraction& frc)  {
    int nummerator = (numerator * frc.denominator) / (frc.numerator * denominator);
    int denominator = denominator * frc.denominator;
    return Fraction(numerator, denominator);
}

bool Fraction :: operator==(const Fraction& frc) const{
    if (this ->numerator == frc.getNumerator() && this ->denominator == frc.getDenominator()){
        return true;
    }
    return false;
}

bool Fraction :: operator!=(const Fraction& frc) const{
    if ((this ->numerator/this->denominator) != (frc.numerator/frc.denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator<=(const Fraction& frc) const{
    if (this ->numerator/this->denominator <= frc.numerator/frc.denominator){
        return true;
    } 
    return false;
}

bool Fraction :: operator<(const Fraction& frc) const{
    if ((this ->numerator/this->denominator) < (frc.numerator/frc.denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator>=(const Fraction& frc) const{
    if ((this ->numerator/this->denominator) >= (frc.numerator/frc.denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator>(const Fraction& frc) const{
    if ((this ->numerator/this->denominator) > (frc.numerator/frc.denominator)){
        return true;
    } 
    return false;
}



Fraction& Fraction ::operator++(){
    this ->numerator += this ->denominator;
    return *this;
    
}


Fraction Fraction::operator++(int) { 

    return Fraction(1, 2); 
}


Fraction& Fraction ::operator--(){
    this ->numerator += this ->denominator;
    return *this;
    
}

Fraction Fraction::operator--(int) { 
     
    return Fraction(1, 2);
        
}


std::ostream& operator<<(std::ostream& output, const Fraction& fraction){
    return output;
}

std::istream& operator>>(std::istream& input, Fraction& fraction){
    return input;
}

}





