#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

char model[21];
char make[21];
char year[6];
int  mileage;
using namespace std;
int get_int(int default_value );
int main() {
    char filename[81];
    int n;

// Note recsize is different for this example.

    int recsize = sizeof(model) + sizeof(make) + sizeof(year) + sizeof(int);
    

    cout << "Enter file name: ";
    cin.getline(filename, 80);

    // Open file for binary write.    

    fstream  fbin(filename, ios::binary | ios::out);
    if (!fbin) {
        cout << "Could not open file " << filename << endl;
 
        return -1;
    }

//  Get record number to write to.

    cout << "Enter file record number: ";
    n = get_int(0);

    // Get data from end user.

    cout << "Enter model: ";
    cin.getline(model, 20);
    cout << "Enter make: ";
    cin.getline(make, 20);
    cout << "Enter year: ";
    cin.getline(year, 20);
    cout << "Enter mileage: ";
    mileage = get_int(0);

    // Write data to the file.
 
    fbin.seekp(n * recsize);
    fbin.write(model, 20);
    fbin.write(make, 20);
    fbin.write(year, 20);
    fbin.write(reinterpret_cast<char*>(&mileage), sizeof(int));
    fbin.close();
    
    return 0;
}

// Get integer function
// Get an integer from keyboard; return default
//  value if user enters 0-length string.
//
int get_int(int default_value) {
    char s[81];

    cin.getline(s, 80);
    if (strlen(s) == 0)
         return default_value;
    return atoi(s);
}

