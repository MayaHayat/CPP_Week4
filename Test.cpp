#include <sstream>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>

#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

// #1
TEST_CASE("Make sure constructor works properly") {
    Fraction fr1(1,4);
    Fraction fr2(5,3);

    CHECK_NOTHROW(fr1.getDenominator());
    CHECK_NOTHROW(fr1.getNumerator());

    CHECK(fr1.getNumerator() == 1);
    CHECK(fr2.getNumerator() == 5);

    CHECK(fr1.getDenominator() == 4);
    CHECK(fr2.getDenominator() == 3); 

}

// #2
TEST_CASE("Check addition & substraction - simple") {
    Fraction fr1(2,4);
    Fraction fr2(1,4);
    CHECK((fr1+fr2) == Fraction(3,4));
    CHECK((fr1-fr2) == Fraction(1,4));
    Fraction fr3 = 0.25 + fr2;
    CHECK(fr3 == Fraction(2,4));
    Fraction fr4 = 0.25-fr2;
    CHECK(fr4 == Fraction(0,4));
}

// #3
TEST_CASE("Check addition & substraction - harder") {
    Fraction fr1(1,4);
    Fraction fr2(1,8);

    CHECK((fr1+fr2) == Fraction(3,8));
    CHECK((fr1-fr2) == Fraction(1,8));
}

// #4
TEST_CASE("Check addition & substraction - difficult") {
    Fraction fr1(1,4);
    Fraction fr2(1,3);

    Fraction sum(7,12);
    Fraction ans = fr1+fr2;
    CHECK(ans == sum);
    CHECK_NOTHROW(fr1+fr2);
    CHECK(fr1+2.1 == (2.35));
    CHECK(fr1-0.25 == (1/4));

    CHECK(fr1+2.5 == Fraction(2.75));
    CHECK(Fraction(3,4)+0.5 == Fraction(5,4));

    CHECK(fr1-2.5 == Fraction(-2.25));
    CHECK(Fraction(3,4)-0.5 == Fraction(1,4));
    
}

// #5
TEST_CASE("Check multiplication & divition") {
    Fraction fr1(1,4);
    Fraction fr2(2,4);

    Fraction ans1 = fr1*fr2;
    Fraction ans2 = fr1/fr2;
    CHECK(ans1 == 0.125);
    CHECK(ans2 == 0.5);
    
    CHECK((fr1*fr2) == Fraction(1,8));
    CHECK((fr2/fr1) == Fraction(2));
}

// #6
TEST_CASE("Denominator cannot be zero, numerator can") {
    Fraction frc(1,1);
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(frc.setDenominator(0));

    Fraction frc2(0,1);
    Fraction frc3(-0,5);
    CHECK(frc2 == frc3);
    CHECK_NOTHROW(frc.setNumerator(0));

}

// #7
TEST_CASE("Fraction should be simplified") {
    CHECK(Fraction(4,8) == Fraction(1,2));
    CHECK(Fraction(0,1) == Fraction(0,2));
}

// #8
TEST_CASE("Make sure setting works properly") {
    Fraction fr1(1,4);
    Fraction fr2(5,3);

    CHECK_NOTHROW(fr1.setNumerator(5));
    CHECK(fr1.getNumerator() == 5);
    CHECK_NOTHROW(fr2.setDenominator(5));
    CHECK(fr2.getDenominator() == 5);
}


// #9
TEST_CASE("Make sure ++ & -- work properly on both sides") {
    Fraction fr1(1,4);
    Fraction fr2(5,3);

    CHECK_NOTHROW(fr1++);
    CHECK_NOTHROW(fr1--);
    CHECK_NOTHROW(++fr2);
    CHECK_NOTHROW(--fr2);

    Fraction fr3(2,4);
    Fraction fr4(9,3);
    CHECK( fr3++ == Fraction(1,2));
    CHECK( fr4-- == Fraction(3,1));
    CHECK( ++fr3 == Fraction(5,2));
    CHECK( --fr4 == Fraction(1,1));

}

// #10
TEST_CASE("Check the reduce function") {
    Fraction fr1(2,4);
    Fraction fr2(9,3);

    fr1.reduce();
    fr2.reduce();

    CHECK( fr1 == Fraction(1,2));
    CHECK( fr2 == Fraction(3,1));

    CHECK(Fraction(3,5) == Fraction(6,10));
    CHECK(Fraction(-1,5) == Fraction(1,-5));

}


// #11
TEST_CASE("Check all multiplications") {
    Fraction fr1(2,4);
    Fraction fr2(9,3);

    CHECK( fr1*2 == Fraction(2,2));
    CHECK( 2*fr1 == Fraction(2,2));
    CHECK( fr2*4 == Fraction(12,1));
    CHECK( 4*fr2 == Fraction(12,1));

    CHECK(fr1*fr2 == Fraction(3,2));
    CHECK_FALSE(fr2*fr1 == Fraction(2,2));


    CHECK_FALSE(fr1*2 == Fraction(1,2));
    CHECK_FALSE(fr1*4 == Fraction(1,2));
}

// #12
TEST_CASE("Check all divisions") {
    Fraction fr1(2,4);
    Fraction fr2(9,3);

    CHECK( fr1/2 == 0.25);
    CHECK( 2/fr1 == Fraction(8,2));
    CHECK( fr2/4 == 0.75);
    CHECK( 4/fr2 == Fraction(1333,1000));

    CHECK(fr2/fr1 == 6);

    CHECK_FALSE(fr1/2 == Fraction(1,2));
    CHECK_FALSE(fr1/4 == Fraction(1,2));
}

// #13
TEST_CASE("Test comparisons left side") {
    Fraction fr1(1,2);
    Fraction fr2(9,3);

    CHECK(fr1 < 0.51);
    CHECK(fr1 > 0.25);
    CHECK_FALSE(++fr1 == 1.3);
    CHECK(fr1  == 1.5);

    CHECK(fr2++ <= 4.1);
    CHECK(--fr2 >= -1.2);
    CHECK_FALSE(fr1 == fr2);
    CHECK_FALSE(fr2 <-3);

}

// #14
TEST_CASE("Test comparisons right side") {
    Fraction fr1(1,2);
    Fraction fr2(9,3);

    CHECK(1 > fr1);
    CHECK(2 < fr2);
    CHECK_FALSE(1 == fr1);
    CHECK(0.5 == fr1);


    CHECK(3.2 <= fr1+3);
    CHECK(fr1<= fr2);
    CHECK(2.5 >= --fr2);
    CHECK_FALSE(fr1>= fr2);
    CHECK_FALSE(3 == fr2);
    CHECK(3 == ++fr2);

}

// #15
TEST_CASE("Test >> sign") {
    std::stringstream ss_in("1 -2 6 9");
    Fraction frc1, frc2;
    ss_in >> frc1 >> frc2;

    CHECK(frc1 == Fraction(-1,2));
    CHECK(frc2 ==Fraction(6,9));

    std::stringstream ss_in2("2 -4 1 72");
    Fraction frc3, frc4;
    ss_in2 >> frc3>> frc4;

    CHECK(frc1 == frc3);
    CHECK(frc1 < frc4);
    CHECK_FALSE(frc1>frc2);


}

// #16
TEST_CASE("Check INT_MAXInt"){
    
    CHECK_NOTHROW(Fraction f1(INT_MAX, 1));

    Fraction frc1(INT_MAX, 1);
    CHECK(frc1 == Fraction(INT_MAX, 1));
    CHECK_THROWS(frc1+1);

    Fraction frc2(INT_MAX, 2);
    CHECK(frc2 == Fraction(INT_MAX, 2));
    CHECK_THROWS(frc2*3);


}
