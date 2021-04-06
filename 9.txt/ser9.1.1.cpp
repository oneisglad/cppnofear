#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

#define SCR_LINES   24    

int main(int argc, char *argv[]) {
    int c;   
    int i;   
    char filename[81];
    char input_line[81];

    if (argc > 1)
        strncpy(filename, argv[1], 80);
    else {
        cout << "Enter a file name and press ENTER: ";
        cin.getline(filename, 80);
    }

    ifstream file_in(filename);

    if (! file_in) {
        cout << "File " << filename << " could not be opened." << endl;
        system("PAUSE");
        return -1;
    }

    while (1) {
        for (i = 1; i <= SCR_LINES && ! file_in.eof(); i++) {
            file_in.getline(input_line, 80);
            cout << input_line << endl;
        }
        if (file_in.eof())
            break;
        cout << endl << "More? (Press 'Q' and ENTER to quit.)";
        cin.getline(input_line, 80);
        c = input_line[0];
        if (c == 'Q' || c == 'q')
            break;
    }
    system("PAUSE"); 
    return 0;
}

