#pragma once
#include <iostream>

namespace ariel
{
    class Fraction
    {
        private:

            int numerator;
            int denominator;
    
        public:
    
            Fraction(int numerator, int denominator);

            const Fraction operator+(Fraction other)const;
            const Fraction operator+(float other)const;
            friend const Fraction operator+(float one, Fraction two);

            const Fraction operator-(Fraction other)const;
            const Fraction operator-(float other)const;
            friend const Fraction operator-(float one, Fraction two);

            const Fraction operator*(Fraction other)const;
            const Fraction operator*(float other)const;
            friend const Fraction operator*(float one, Fraction two);

            const Fraction operator/(Fraction other)const;
            const Fraction operator/(float other)const;
            friend const Fraction operator/(float one, Fraction two);

            bool operator==(Fraction other)const;
            bool operator==(float other)const;
            friend bool operator==(float one, Fraction two);

            bool operator>(Fraction other)const;
            bool operator>(float other)const;
            friend bool operator>(float one, Fraction two);

            bool operator<(Fraction other)const;
            bool operator<(float other)const;
            friend bool operator<(float one, Fraction two);

            bool operator>=(Fraction other)const;
            bool operator>=(float other)const;
            friend bool operator>=(float one, Fraction two);
        
            bool operator<=(Fraction other)const;
            bool operator<=(float other)const;
            friend bool operator<=(float one, Fraction two);

            Fraction& operator++();
            const Fraction operator++(int postfix_increment);

            Fraction& operator--();
            const Fraction operator--(int postfix_decrement);    

            friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
            friend std::istream& operator>>(std::istream& is, Fraction& obj);
    };
}