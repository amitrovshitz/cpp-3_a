#include "Fraction.hpp"
using namespace std;


 namespace ariel
 {
            Fraction::Fraction():numerator(0), denominator(1){}
            Fraction::Fraction(int num, int den):numerator(num), denominator(den) {
                if(denominator == 0)
                {
                    throw invalid_argument("not ilegal.");
                }

                if(num < 0 && den < 0)
                {
                    numerator *= -1;
                    denominator *= -1;
                }

                else if(den < 0)
                {
                    numerator *= -1;
                    denominator *= -1;  
                }

                reduce();
            }
            Fraction::Fraction(const float& num){
                float  copy = num;
                int pow = 1;
                while(copy != (int)num && pow <1000)
                {
                    pow *= 10;
                    copy *= 10;
                }

                numerator = copy;
                denominator = pow;

                reduce();
            }
            int Fraction::gcd(int f_number, int s_number)
            {
                if (s_number == 0)
                {
                    return f_number;
                }
                return gcd(s_number, f_number % s_number);
            }

            void Fraction::reduce()
            {   
                int gcdNum = gcd(numerator, denominator);
                numerator /= gcdNum;
                denominator /= gcdNum;
            }

            const Fraction Fraction::operator+(const Fraction& other)const
            {
                int num = (other.denominator * numerator) + (denominator * other.numerator);
                int den = other.denominator * denominator;
                
                return Fraction(num, den);
            }

            const Fraction Fraction::operator+(const float& other)const
            {
                return *this + Fraction(other);
            }

            const Fraction operator+(const float& one, const Fraction& two)
            {
                return Fraction(one) + two;
            }

            const Fraction Fraction::operator-(const Fraction& other)const
            {
                            {
                int num = (other.denominator * numerator) - (denominator * other.numerator);
                int den = other.denominator * denominator;
                
                return Fraction(num, den);
            }
            }

            const Fraction Fraction::operator-(const float& other)const
            {
                return *this - Fraction(other);
            }

            const Fraction operator-(const float& one, const Fraction& two)
            {
                return Fraction(one) - two;
            }

            const Fraction Fraction::operator*(const Fraction& other)const
            {
                int num = other.numerator * numerator;
                int den = other.denominator * denominator;

                return Fraction(num, den);
            }

            const Fraction Fraction::operator*(const float& other)const
            {
                return *this * Fraction(other);
            }

            const Fraction operator*(const float& one, const Fraction& two)
            {
                return Fraction(one) * two;
            }

            const Fraction Fraction::operator/(const Fraction& other)const
            {
                if(other.numerator == 0)
                {
                    throw invalid_argument("cant divide by zero.");
                }
                int num = numerator * other.denominator;
                int den = denominator * other.numerator;

                return Fraction(num, den);


            }

            const Fraction Fraction::operator/(const float& other)const
            {
                return *this / Fraction(other);
            }

            const Fraction operator/(const float& one, const Fraction& two)
            {
                return Fraction(one) / two;
            }

            bool Fraction::operator==(const Fraction& other)const
            {
                return (numerator == other.numerator && denominator == other.denominator);
            }

            bool Fraction::operator==(const float& other)const
            {
                return (*this == Fraction(other));
            }

            bool operator==(const float& one, const Fraction& two)
            {
                return (Fraction(one) == two);
            }

            bool Fraction::operator>(const Fraction& other)const
            {
                return ((numerator * other.denominator) > (denominator * other.numerator));
            }

            bool Fraction::operator>(const float& other)const
            {
                return (*this > Fraction(other));
            }

            bool operator>(const float& one, const Fraction& two)
            {
                return (Fraction(one) > two);
            }

            bool Fraction::operator<(const Fraction& other)const
            {
                return ((numerator * other.denominator) < (denominator * other.numerator));
            }

            bool Fraction::operator<(const float& other)const
            {
                return (*this < Fraction(other));
            }

            bool operator<(const float& one, const Fraction& two)
            {
                return (Fraction(one) < two);
            }

            bool Fraction::operator>=(const Fraction& other)const
            {
                return ((*this > other) || (*this == other));
            }

            bool Fraction::operator>=(const float& other)const
            {
                return (*this >= (Fraction(other)));
            }

            bool operator>=(const float& one, const Fraction& two)
            {
                return (Fraction(one) >= two);
            }
        
            bool Fraction::operator<=(const Fraction& other)const
            {
                return ((*this < other) || (*this == other));
            }

            bool Fraction::operator<=(const float& other)const
            {
                return (*this <= (Fraction(other)));
            }

            bool operator<=(const float& one, const Fraction& two)
            {
                return (Fraction(one) <= two);
            }

             Fraction& Fraction::operator+=(const Fraction& other)
            {
                numerator = (other.denominator * numerator) + (denominator * other.numerator);
                denominator = other.denominator * denominator;
                reduce();

                return *this;
            }

            Fraction& Fraction::operator-=(const Fraction& other)
            {
                numerator = (other.denominator * numerator) - (denominator * other.numerator);
                denominator = other.denominator * denominator;
                reduce();

                return *this;
            }

            Fraction& Fraction::operator++()
            {
                *this += Fraction(denominator, denominator);
                return *this;
            }

            const Fraction Fraction::operator++(int postfix_increment)
            {
                Fraction copy = *this;
                ++(copy);
                return copy;
            }

            Fraction& Fraction::operator--()
            {
                *this -= Fraction(denominator, denominator);
                return *this;
            }

            const Fraction Fraction::operator--(int postfix_decrement)
            {
                Fraction copy = *this;
                --(copy);
                return copy;            
            } 

            ostream& operator<<(ostream& oss, const Fraction& obj)
            {
                return oss << obj.numerator << '/' << obj.denominator;
            }

            istream& operator>>(istream& iss, Fraction& obj)
            {
                int numerator;
                int denominator;
                char s;

                iss >> numerator >> s >> denominator;
                if(s != '/')
                {
                    throw invalid_argument("ilegal");
                }

                obj = Fraction(numerator, denominator);
                return iss;
            }
 }