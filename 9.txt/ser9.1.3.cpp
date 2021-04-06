// Exercise 09.01.03.txt
// This program just prints out all the command-line arguments,
//  one to a line.

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    int i;   // loop counter

    for (i = 0; i < argc; i++)
        cout << argv[i] << endl;

    
  std::getchar();
}

