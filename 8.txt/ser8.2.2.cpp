#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

void convert_to_upper(char *s);   // function prototype added

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

    while (1) {
        for (i = 1; i <= 24 && ! file_in.eof(); i++) {
            file_in.getline(input_line, 80);
            convert_to_upper(input_line);      // convert
            cout << input_line << endl;
        }
        if (file_in.eof())
            break;
        cout << "More? (Press 'Q' and ENTER to quit.)";
        cin.getline(input_line, 80);
        c = input_line[0];
        if (c == 'Q' || c == 'q')
            break;
    }
    
    return 0;
}

// Convert-to-all-uppercase function
// For convenience, the direct-ptr version is used here.

void convert_to_upper(char *s) {
    for (; *s; s++)
         *s = toupper(*s);
}

