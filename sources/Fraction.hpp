#pragma once
#include <iostream>

namespace ariel
{
    class Fraction
    {
        private:

            int numerator;
            int denominator;
            void reduce();
            static int gcd(int f_number, int s_number);
    
        public:
            explicit Fraction();    
            explicit Fraction(int numerator, int denominator);
            explicit Fraction(const float& other);

            const Fraction operator+(const Fraction& other)const;
            const Fraction operator+(const float& other)const;
            friend const Fraction operator+(const float& one, const Fraction& two);

            const Fraction operator-(const Fraction& other)const;
            const Fraction operator-(const float& other)const;
            friend const Fraction operator-(const float& one, const Fraction& two);

            const Fraction operator*(const Fraction& other)const;
            const Fraction operator*(const float& other)const;
            friend const Fraction operator*(const float& one, const Fraction& two);

            const Fraction operator/(const Fraction& other)const;
            const Fraction operator/(const float& other)const;
            friend const Fraction operator/(const float& one, const Fraction& two);

            bool operator==(const Fraction& other)const;
            bool operator==(const float& other)const;
            friend bool operator==(const float& one, const Fraction& two);

            bool operator>(const Fraction& other)const;
            bool operator>(const float& other)const;
            friend bool operator>(const float& one, const Fraction& two);

            bool operator<(const Fraction& other)const;
            bool operator<(const float& other)const;
            friend bool operator<(const float& one, const Fraction& two);

            bool operator>=(const Fraction& other)const;
            bool operator>=(const float& other)const;
            friend bool operator>=(const float& one, const Fraction& two);
        
            bool operator<=(const Fraction& other)const;
            bool operator<=(const float& other)const;
            friend bool operator<=(const float& one, const Fraction& two);

            Fraction& operator+=(const Fraction& other);
            Fraction& operator-=(const Fraction& other);

            Fraction& operator++();
            const Fraction operator++(int postfix_increment);

            Fraction& operator--();
            const Fraction operator--(int postfix_decrement);    

            friend std::ostream& operator<<(std::ostream& oss, const Fraction& obj);
            friend std::istream& operator>>(std::istream& iss, Fraction& obj);
    };
}