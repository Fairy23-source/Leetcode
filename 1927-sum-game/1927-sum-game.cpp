class Solution {
public:
    bool sumGame(string num) {

        int n = num.length();
        int half = n / 2;

        int leftSum = 0;
        int rightSum = 0;

        int leftQ = 0;
        int rightQ = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?') {
                leftQ++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?') {
                rightQ++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        // Odd number of '?' -> Alice wins
        if ((leftQ + rightQ) % 2 == 1) {
            return true;
        }

        // Bob can make the sums equal only in this exact case
        return leftSum - rightSum != (rightQ - leftQ) * 9 / 2;
    }
};