/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(1,2), b(3,9);

    cout << "a: " << a << "b: " << b << endl;

    cout << "a+b" << a+b << endl; 
    cout << "a-b" << a-b << endl; 

    cout << "a+3.2" << a+3.2 << endl;
    cout << "3.2-b" << 3.2-b << endl;

    cout << "a/b" << a/b << endl; 
    cout << "a*b" << a*b << endl; 

    cout << "1/b" << 1/b << endl; 
    cout << "a/3" << a/3 << endl; 

    cout << "2.3*b" << 2.3*b << endl; 
    cout << "a+2.421" << a+2.421 << endl; 

    Fraction c = a+b-1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "if a<b print true else false" << (a<b) << endl; 
    cout << "if a>b print true else false" << (a>b) << endl; 
    cout << "if a<=b print true else false" << (a<=b) << endl; 
    cout << "if a>=b print true else false" << (a>=b) << endl; 
    

}