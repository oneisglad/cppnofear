#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main() {
    int c;   // input character
    int i;   // loop counter
    char filename[81];
    char input_line[81];

    cout << "Enter a file name and press ENTER: ";
    cin.getline(filename, 80);

    ifstream file_in(filename);

    if (! file_in) {
        cout << "File " << filename << " could not be opened." << endl;
    
        return -1;
    }

    int lines_to_read = 20;    // Number of lines to read; default = 20

    while (1) {
        for (i = 1; i <= lines_to_read && ! file_in.eof(); i++) {
            file_in.getline(input_line, 80);
            cout << input_line << endl;
        }
        if (file_in.eof())
            break;
        cout << "More? (Press 'Q' and ENTER to quit, or # lines to print.)>";
        cin.getline(input_line, 80);
        c = input_line[0];
        if (c == 'Q' || c == 'q')
            break;
        else if (strlen(input_line) > 0)       // If user input something
            lines_to_read = atoi(input_line);  //  set new value of lines_to_read
    }
   
    return 0;
}

