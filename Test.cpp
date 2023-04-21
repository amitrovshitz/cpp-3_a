#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"
#include <sstream>

using namespace std;
using namespace ariel;

//1
TEST_CASE("create fraction and check that not throw exception.")
{
    CHECK_NOTHROW(Fraction(1,8));
    CHECK_NOTHROW(Fraction(2,8));
    CHECK_NOTHROW(Fraction(4,8));
    CHECK_NOTHROW(Fraction(8,8));

}
//2
TEST_CASE("check that the constructor reduce the fraction.")
{
    CHECK(Fraction(1,8) == Fraction(1,8));
    CHECK(Fraction(2,8) == Fraction(1,4));
    CHECK(Fraction(4,8) == Fraction(1,2));
    CHECK(Fraction(8,8) == Fraction(1,1));
}
//3
TEST_CASE("the constructor throw execption when build number with denominator")
{
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(-2,0));
    CHECK_THROWS(Fraction(4,-0));
    CHECK_THROWS(Fraction(-8,0));
    
}
//4
TEST_CASE("when the numerator is zero not throw excption.")
{
    CHECK_NOTHROW(Fraction(0,2));
    CHECK_NOTHROW(Fraction(0,-10));
}
//5
TEST_CASE("Division by zero throws an exception.")
{
 Fraction a(1,8);
 Fraction b(0);
 CHECK_THROWS(a/b);
}
//6
TEST_CASE("increment the fraction.")
{
    Fraction a(1,4);
    Fraction b(-2,5);
    CHECK(++a == Fraction(5,4));
    CHECK(++b == Fraction(3,5));
}
//7
TEST_CASE("decrement the fraction.")
{
    Fraction a(1,4);
    Fraction b(-2,5);
    CHECK(--a == Fraction(-3,4));
    CHECK(--b == Fraction(-7,5));
}
//8
TEST_CASE("post increment/decrement returns different fraction object") 
{
    Fraction f(1, 2);
    Fraction g = f++;
    Fraction h = f--;
    CHECK(&g != &f); // verify that g is a different object than f
    CHECK(&h != &f); // verify that h is a different object than f
}
//9
TEST_CASE("comparison operations.")
{
 Fraction a(1,3);
 Fraction b(4,3);
 CHECK(b > a);
 CHECK(b > 1.01);
 CHECK(2.34 > b);
  CHECK(a < b);
 CHECK(a < 0.67);
 CHECK(0.1 < a);

}
//10
TEST_CASE("The == operator to compare two fractions for equality")
{
    Fraction a(1,2);
    Fraction b(4,8);
    CHECK(a == b);
    CHECK(0.5 == a);
    CHECK(b == 0.5);   
}
//11
TEST_CASE("The + operator to add two fractions and float.")
{ 
    Fraction a(1,2);
    Fraction b(4,8);
    CHECK((a + b) == 1);
    CHECK((a + 0.5) == 1);
    CHECK(1 == (a + b));
    CHECK((0.5 + a) == 1);

}
//12
TEST_CASE("The - operator to subtract two fractions and float.")
{
    Fraction a(1,2);
    Fraction b(2,8);
    CHECK((a - b) == 0.25);
    CHECK((0.5 - b) == 0.25);
    CHECK(1 == (1.25 - b));
}
//13
TEST_CASE("The * operator to multiply two fractions and float.")
{
    Fraction a(1,2);
    Fraction b(2,8);
    CHECK((a * b) == 0.125);
    CHECK((0.5 * b) == 0.125);
    CHECK(b == (a * 0.5));

}
//14
TEST_CASE("The / operator to divide two fractions and float.")
{
    Fraction a(1,2);
    Fraction b(2,8);
    CHECK((a / b) == 2);
    CHECK((0.5 / b) == 2);
    CHECK(1 == (a / 0.5));
}
//15
TEST_CASE("The << operator to print a fraction to an output stream in the format “numerator/denominator.")
{ 
    Fraction a(1,2);
    Fraction b(0,8);

    CHECK_NOTHROW(cout << a << endl);
    CHECK_NOTHROW(cout << b << endl);
}
//16
TEST_CASE("The >> operator to read a fraction from an input stream by taking two integers as input.")
{
    std::istringstream input1("3/4");
    Fraction fraction1;
    CHECK_NOTHROW(input1 >> fraction1);

    std::istringstream input2("3/-4");
    Fraction fraction2;
    CHECK_NOTHROW(input2 >> fraction2);
}

//17
TEST_CASE("The << operator throw excption when betwwen the integers not gets /.")
{
    std::istringstream input3("3:4");
    Fraction fraction;
    CHECK_THROWS_AS(input3 >> fraction, std::invalid_argument);
}
//18
TEST_CASE("defualt constractor.")
{
  Fraction a;
  CHECK(a == 0);  
}
//19
TEST_CASE("reduce the fraction when is zero(numerator).")
{
    Fraction a(0,8);
    CHECK(a == 0);
}
//20
TEST_CASE("reduce the fraction 0/x to 0/1.")
{
    Fraction a(0,5);
    Fraction b(0,3);
    CHECK(a == Fraction(0,1));
    CHECK(b == Fraction(0,1));

}