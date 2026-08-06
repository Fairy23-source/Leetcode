#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter a sentence: ";
    getline(cin, s);

    int i = s.length() - 1;
    int count = 0;

    // Skip spaces at the end
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    cout << "Length of last word: " << count << endl;

    return 0;
}
