#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;

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
    Fraction fr1(1,4);
    Fraction fr2(2,4);

    Fraction sum(3,4);
    Fraction ans = fr1+fr2;

    CHECK(ans == sum);

}

// #3
TEST_CASE("Check addition - harder") {
    Fraction fr1(1,4);
    Fraction fr2(1,8);

    Fraction sum(3,8);
    Fraction ans = fr1+fr2;

    CHECK(ans == sum);
}

// #4
TEST_CASE("Check addition - difficult") {
    Fraction fr1(1,4);
    Fraction fr2(1,3);

    Fraction sum(7,12);
    Fraction ans = fr1+fr2;
    CHECK(ans == sum);
}

// #5
TEST_CASE("Check multiplication") {
    Fraction fr1(1,4);
    Fraction fr2(2,4);

    Fraction sum(1,8);
    Fraction ans = fr1*fr2;

    CHECK(ans == sum);
}

// #6
TEST_CASE("Denominator cannot be zero") {
    Fraction fr1(1,0);
    CHECK_THROWS(fr1.getDenominator());
}


