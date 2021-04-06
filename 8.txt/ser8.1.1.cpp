#include <iostream>
#include <fstream>
#include <cstring>   // Add this include
using namespace std;

int main() {
    char filename[81];
    char path[81];

    cout << "Enter directory path: ";   // Prompt for path
    cin.getline(path, 80);

    cout << "Enter a file name and press ENTER: ";
    cin.getline(filename, 80);

    strncat(path, filename, strlen(path) - 80); // concatenate

    ofstream file_out(path);     // Use path string to open
    if (! file_out) {
        cout << "File " << filename << " could not be opened.";
       
        return -1;
    }
    cout << "File " << filename << " was opened." << endl;
    file_out << "I am Blaxxon," << endl;
    file_out << "the cosmic computer." << endl;
    file_out << "Fear me.";
    file_out.close();

    return 0;
}

