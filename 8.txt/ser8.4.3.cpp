#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int get_int(int default_value); 
void write_record();            
void read_record();             

char name[21];                
int  age;

fstream fbin;                   
int recsize;                   



int main() {
    char filename[81];

    int choice = 0; // 
    
    recsize =  sizeof(name) + sizeof(int);
    cout << "Enter file name: ";
    cin.getline(filename, 80);

  

    fbin.open(filename, ios::binary | ios::in | ios::out);
    if (!fbin) {
        cout << "Could not open file " << filename << endl;
        system("PAUSE");
        return -1;
    }

    while(true) {

       

        cout << "Here are the commands:" << endl << endl;
        cout << " 1. Write a record." << endl;
        cout << " 2. Read a record." << endl;
        cout << " 3. Exit." << endl;
        cout << "What is your command (enter 1,2,3)? ";
        choice = get_int(0);
        if (choice == 1)
             write_record();
        else if (choice == 2)
             read_record();
        else if (choice == 3) {
             fbin.close();
             system("PAUSE");
             return 0;
        } else 
             cout << "Bad input. Re-enter..." << endl << endl;

    }  
}  



void write_record() {
    int recnum = 0;  

   

    cout << "Enter file record number: ";
    recnum = get_int(0);    
    fbin.seekp(recnum * recsize);

    
    
    cout << "Enter name: ";
    cin.getline(name, 20);
    cout << "Enter age: ";
    age = get_int(0);

 

    fbin.write(name, 20);
    fbin.write(reinterpret_cast<char*>(&age), sizeof(int));
    cout << "Data written successfully." << endl;
}
    

void read_record() {
    int recnum = 0;  

   

    cout << "Enter file record number: ";
    recnum = get_int(0);    
    fbin.seekp(recnum * recsize);



    fbin.read(name, 20);
    fbin.read(reinterpret_cast<char*>(&age), sizeof(int));

    
    
    cout << "The name is: " << name << endl;
    cout << "The age is: " << age << endl;
}
    


int get_int(int default_value) {
    char s[81];

    cin.getline(s, 80);
    if (strlen(s) == 0)
         return default_value;
    return atoi(s);
}

