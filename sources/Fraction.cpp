#include "Fraction.hpp"
using namespace std;


 namespace ariel
 {
            Fraction::Fraction(int num, int den):numerator(num), denominator(den) {}

            const Fraction Fraction::operator+(Fraction other)const{return other;}
            const Fraction Fraction::operator+(float other)const{return *this;}
            const Fraction operator+(float one, Fraction two){return two;}

            const Fraction Fraction::operator-(Fraction other)const{return other;}
            const Fraction Fraction::operator-(float other)const{return *this;}
            const Fraction operator-(float one, Fraction two){return two;}

            const Fraction Fraction::operator*(Fraction other)const{return other;}
            const Fraction Fraction::operator*(float other)const{return *this;}
            const Fraction operator*(float one, Fraction two){return two;}

            const Fraction Fraction::operator/(Fraction other)const{return other;}
            const Fraction Fraction::operator/(float other)const{return *this;}
            const Fraction operator/(float one, Fraction two){return two;}

            bool Fraction::operator==(Fraction other)const{return true;}
            bool Fraction::operator==(float other)const{return true;}
            bool operator==(float one, Fraction two){return true;}

            bool Fraction::operator>(Fraction other)const{return true;}
            bool Fraction::operator>(float other)const{return true;}
            bool operator>(float one, Fraction two){return true;}

            bool Fraction::operator<(Fraction other)const{return true;}
            bool Fraction::operator<(float other)const{return true;}
            bool operator<(float one, Fraction two){return true;}

            bool Fraction::operator>=(Fraction other)const{return true;}
            bool Fraction::operator>=(float other)const{return true;}
            bool operator>=(float one, Fraction two){return true;}
        
            bool Fraction::operator<=(Fraction other)const{return true;}
            bool Fraction::operator<=(float other)const{return true;}
            bool operator<=(float one, Fraction two){return true;}

            Fraction& Fraction::operator++(){return *this;}
            const Fraction Fraction::operator++(int postfix_increment){return *this;}

            Fraction& Fraction::operator--(){return *this;}
            const Fraction Fraction::operator--(int postfix_decrement){return *this;}   

            ostream& operator<<(ostream& os, const Fraction& obj){return os;}
            istream& operator>>(istream& is, Fraction& obj){return is;}
 }



