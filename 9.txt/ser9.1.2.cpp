#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(int argc, char *argv[]) {
    int c;   // input character
    int i;   // loop counter
    char readtxt3.txt[81];
    char input_line[81];
 if (argc > 1)
        strncpy(readtxt3.txt, argv[1], 80);
    else {
        cout << "Program requires a filename argument." << endl;
        return -1;
    }
ifstream file_in(readtxt3.txt);
 if (! file_in) {
        cout << "File " << readtxt3.txt << " could not be opened." << endl;
     return -1;
    }
 while (1) {
    for (i = 1; i <= 24 && ! file_in.eof(); i++) {
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
    cin.get();
	cin.get();
  return 0;
   std::getchar();
}

