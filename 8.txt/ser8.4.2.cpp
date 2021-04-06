#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int get_int(int default_value);
char name[20];

int main() {
    char filename[81];
    int n;
    int age;
    int recsize =  sizeof(name) + sizeof(int);
    

    cout << "Enter file name: ";
    cin.getline(filename, 80);

   

    fstream  fbin(filename, ios::binary | ios::in);
    if (!fbin) {
        cout << "Could not open file " << filename << endl;
        system("PAUSE");
        return -1;
    }

	while(1) {

  

        cout << "Enter file record number (-1 to quit): ";
        n = get_int(-1);
		if (n == -1)
		    break;
        
		fbin.seekp(n * recsize);


        fbin.read(name, 20);
        fbin.read(reinterpret_cast<char*>(&age), sizeof(int));

    
        cout << "The name is: " << name << endl;
        cout << "The age is: " << age << endl;
    }
    fbin.close();
    system("PAUSE");
    return 0;
}


int get_int(int default_value) {
    char s[81];

    cin.getline(s, 80);
    if (strlen(s) == 0)
         return default_value;
    return atoi(s);
}

