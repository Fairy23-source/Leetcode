#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    string a, b;

    cout << "Enter first binary number: ";
    cin >> a;

    cout << "Enter second binary number: ";
    cin >> b;

    string ans = "";

    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {

        int sum = carry;

        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        ans += (sum % 2) + '0';
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());

    cout << "Sum = " << ans << endl;

    return 0;
}
