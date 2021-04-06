// Exercise 14.01.01
// This program alters new1.cpp to use double as the
//  base type for the array rather than int.

#include <iostream>
using namespace std;

int main() {
    double sum = 0.0;     // TYPE ALTERED TO DOUBLE HERE.
    int n;
    double *p;            // TYPE OF *p ALTERED TO DOUBLE.

    cout << "Enter number of items: ";
    cin >> n;

    p = new double[n];     // Allocate n double -- ALTERED FROM INT

    for (int i = 0; i < n; i++) {
        cout << "Enter item #" << i << ": ";
        cin >> p[i];
        sum += p[i];
    }
    cout << "Here are the items: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << ", ";
    cout << endl;
    cout << "The total is: " << sum << endl;
    cout << "The average is: " << sum / n << endl;

    delete [] p;       // Release n integers.

    system("PAUSE");
    return 0;
}
