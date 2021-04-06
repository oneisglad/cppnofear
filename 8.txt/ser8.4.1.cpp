#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int get_int(int default_value);



char model[21];
char make[21];
char year[6];
int  mileage;

int main() {
    char filename[81];
    int n;



    int recsize = sizeof(model) + sizeof(make) + sizeof(year) + sizeof(int);
    

    cout << "Enter file name: ";
    cin.getline(filename, 80);



    fstream  fbin(filename, ios::binary | ios::in);
    if (!fbin) {
        cout << "Could not open file " << filename << endl;
        system("PAUSE");
        return -1;
    }



    cout << "Enter file record number: ";
    n = get_int(0);
    fbin.seekp(n * recsize);



    fbin.read(model, 20);
    fbin.read(make, 20);
    fbin.read(year, 5);
    fbin.read(reinterpret_cast<char*>(&mileage), sizeof(int));


    
    cout << "The model is: " << model << endl;
    cout << "The make is: " << make << endl;
    cout << "The year is: " << year << endl;
    cout << "The mileage is: " << mileage << endl;
    fbin.close();
    system("PAUSE");
    return 0;
}

// Get integer function

int get_int(int default_value) {
    char s[81];

    cin.getline(s, 80);
    if (strlen(s) == 0)
         return default_value;
    return atoi(s);
}

