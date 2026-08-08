#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {

        // Skip spaces and special characters from left
        if (!isalnum(s[left])) {
            left++;
        }

        // Skip spaces and special characters from right
        else if (!isalnum(s[right])) {
            right--;
        }

        // Compare characters
        else {
            if (tolower(s[left]) != tolower(s[right])) {
                cout << "Not a Palindrome" << endl;
                return 0;
            }

            left++;
            right--;
        }
    }

    cout << "Valid Palindrome" << endl;

    return 0;
}
