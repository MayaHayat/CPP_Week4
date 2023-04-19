#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

// #1
TEST_CASE("Make sure constructor works properly") {
    Fraction fr1(1,4);
    Fraction fr2(5,3);

    CHECK(fr1.getNumerator() == 1);
    CHECK(fr2.getNumerator() == 5);

    CHECK(fr1.getDenominator() == 4);
    CHECK(fr2.getDenominator() == 3); 

}

// #2
TEST_CASE("Check addition - simple") {
    Fraction fr1(2,4);
    Fraction fr2(1,4);

    CHECK((fr1+fr2) == Fraction(3,4));
    CHECK((fr1-fr2) == Fraction(1,4));

}

// #3
TEST_CASE("Check addition - harder") {
    Fraction fr1(1,4);
    Fraction fr2(1,8);

    CHECK((fr1+fr2) == Fraction(3,8));
    CHECK((fr1-fr2) == Fraction(1,8));
}

// #4
TEST_CASE("Check addition - difficult") {
    Fraction fr1(1,4);
    Fraction fr2(1,3);

    Fraction sum(7,12);
    Fraction ans = fr1+fr2;
    CHECK(ans == sum);
    CHECK_NOTHROW(fr1+fr2);
}

// #5
TEST_CASE("Check multiplication") {
    Fraction fr1(1,4);
    Fraction fr2(2,4);

    Fraction ans = fr1*fr2;
    
    CHECK((fr1*fr2) == Fraction(1,8));
    CHECK((fr2/fr1) == Fraction(2));
}

// #6
TEST_CASE("Denominator cannot be zero") {
    Fraction frc(1,1);
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(frc.setDenominator(0));

}

// #7
TEST_CASE("Fractions are simplified") {
    CHECK(Fraction(4,8) == Fraction(1,2));
    CHECK(Fraction(0/1) == Fraction(0,2));
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
TEST_CASE("Make sure comparisons work properly") {
    Fraction fr1(1,4);
    Fraction fr2(5,3);

    CHECK_NOTHROW(fr1++);
    CHECK_NOTHROW(fr1--);
    CHECK_NOTHROW(++fr2);
    CHECK_NOTHROW(--fr2);

}

// #10
TEST_CASE(" Check the reduce function") {
    Fraction fr1(2,4);
    Fraction fr2(9,3);

    fr1.reduce();
    fr2.reduce();

    CHECK( fr1 == Fraction(1,2));
    CHECK( fr2 == Fraction(3,1));
}