// Exercise 11.03.01.txt
// This program tests the Fraction class by initializing a series
//  of fractions and then printing their values.
//
// NOTE: Although I used copy-and-paste to generate some of this code,
// the use of arrays is probably the best time saving device. This is
// left as yet another exercise.

#include <cstdlib>
#include <iostream>
using namespace std;

class Fraction {
private:
    int num, den;      // Numerator and denominator.
public:
    void set(int n, int d) {num = n; den = d; normalize();}
    int get_num()  {return num;}
    int get_den()  {return den;}
private:
    void normalize();   // Put fraction into standard form.
    int gcf(int a, int b);   // Greatest Common Factor.
    int lcm(int a, int b);   // Lowest Common Denominator.
};

int main() {

    // HERE ARE THE NEW FRACT VARIABLES

    Fraction f1, f2, f3, f4, f5;

    f1.set(2, 2);       // 2/2
    f2.set(4, 8);       // 4/8
    f3.set(-9, -9);     // -9/-9
    f4.set(10, 50);     // 10/50
    f5.set(100, 25);    // 100/25

    // PRINT THE RESULTING FRACTIONS

    cout << f1.get_num() << "/" << f1.get_den() << endl;
    cout << f2.get_num() << "/" << f2.get_den() << endl;
    cout << f3.get_num() << "/" << f3.get_den() << endl;
    cout << f4.get_num() << "/" << f4.get_den() << endl;
    cout << f5.get_num() << "/" << f5.get_den() << endl;
    system("PAUSE");
    return 0;
}

// ---------------------------------------------------
// FRACTION CLASS FUNCTIONS

// Normalize: put fraction into a standard form, unique
//  for each mathematically different value.
//
void Fraction::normalize(){

    // Handle cases involving 0

    if (den == 0 || num == 0) {
        num = 0;
        den = 1;
    }

    // Put neg. sign in numerator only.

    if (den < 0) {
        num *= -1;
        den *= -1;
    }

    // Factor out GCF from numerator and denominator.

    int n = gcf(num, den);
    num = num / n;
    den = den / n;
}

// Greatest Common Factor
//
int Fraction::gcf(int a, int b) {
    if (a % b == 0)
        return abs(b);
    else
        return gcf(b, a % b);
}

// Lowest Common Multiple
//
int Fraction::lcm(int a, int b){
    return (a / gcf(a, b)) * b;
}
