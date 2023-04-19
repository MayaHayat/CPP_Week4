#include "Fraction.hpp"
#include <iostream>

using namespace std;
namespace ariel{

Fraction :: Fraction(int numerator , int denominator){
    if (denominator == 0 && numerator != 0){
        throw (" Denominator can't be 0");
    }
    this -> numerator = numerator;
    this -> denominator = denominator;
    reduce();
}

Fraction::Fraction(double numerator) {
    this -> numerator = numerator;
    this -> denominator = 1;
    reduce();
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

// -------------------- Help Function ---------------------------

    int Fraction :: getGCD (int numerator, int denominator){
        if (denominator == 0){
            return numerator;
        }
        return (this -> getGCD(denominator, numerator%denominator));
    }

    void Fraction :: reduce(){
        int gcd = this->getGCD(this -> numerator, this -> denominator);
        this -> numerator /= gcd;
        this -> denominator /= gcd;
    }


// --------------- Requested functions ------------------


Fraction Fraction::operator+(Fraction& frc) {

    int num = (this -> numerator * frc.denominator) + (frc.numerator * this -> denominator);
    int den = this -> denominator * frc.denominator;
    return Fraction(num,den);
}

double Fraction::operator+(double num){
    double numerator = this -> numerator + num*this->denominator;
    return (numerator/this -> denominator);
}



Fraction Fraction::operator-(Fraction& frc) {
    int num = (this-> numerator * frc.denominator) - (frc.numerator * this -> denominator);
    int den = this -> denominator * frc.denominator;
    return Fraction(num, den);
}

double Fraction::operator-(double num){
    double numerator = this -> numerator - num*this->denominator;
    return (numerator/this -> denominator);
}

// Fraction operator-(double num, const Fraction &frac){
    
//     return num -(frac.numerator/frac.denominator);
// }


Fraction Fraction::operator*( Fraction& frc)  {
    int num = (this->numerator * frc.numerator);
    int den = this ->denominator * frc.denominator;
    return Fraction(num, den);
}

double Fraction::operator*(double num){
    
    return (this->numerator * num)/this->denominator;
}

Fraction operator*(double num, const Fraction &frac){
    
    return (frac.numerator/frac.denominator)*num;
}


Fraction Fraction::operator/( Fraction& frc)  {
    int num = this -> numerator * frc.denominator;
    int den = this -> denominator * frc.numerator;
    return Fraction(num, den);
}

bool Fraction :: operator==(const Fraction& frc) const{
    if (this -> numerator == frc.numerator && this -> denominator == frc.denominator){
        return true;
    }
    return false;
}


bool Fraction :: operator!=(const Fraction& frc) const{
    if ((this ->numerator/this -> denominator) != (frc.numerator/frc.denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator<=(const Fraction& frc) const{
    if ((this -> numerator* frc.denominator) <= (frc.numerator*this -> denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator<=(double num) const{
    if (this -> numerator <= num*this -> denominator){
        return true;
    } 
    return false;
}

bool Fraction :: operator<(const Fraction& frc) const{
    if ((this -> numerator* frc.denominator) < (frc.numerator*this -> denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator<(double num) const{
    if (this -> numerator < num*this -> denominator){
        return true;
    } 
    return false;
}

bool Fraction :: operator>=(const Fraction& frc) const{
    if ((this -> numerator* frc.denominator) >= (frc.numerator*this -> denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator>=(double num) const{
    if (this -> numerator >= num * this -> denominator){
        return true;
    } 
    return false;
}

bool Fraction :: operator>(const Fraction& frc) const{
    if ((this -> numerator* frc.denominator) > (frc.numerator*this -> denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator>(double num) const{
    if (this -> numerator > num* this->denominator){
        return true;
    } 
    return false;
}



Fraction& Fraction ::operator++(){
    this -> numerator += this -> denominator;
    return *this;
}


Fraction Fraction::operator++(int) { 
    this -> numerator += this -> denominator;
    return *this;
}


Fraction& Fraction ::operator--(){
    this -> numerator -= this -> denominator;
    return *this;
}

Fraction Fraction::operator--(int) { 
     this -> numerator -= this -> denominator;
    return *this;  
}


std::ostream& operator<<(std::ostream& output, const Fraction& fraction){
    return (output << fraction.numerator<< '/' << fraction.denominator);
}

std::istream& operator>>(std::istream& in, Fraction& fraction){
    std::string input;
	in >> input;
	return in;
}

}





