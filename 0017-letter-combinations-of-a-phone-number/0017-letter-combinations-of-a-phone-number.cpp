class Solution {
public:

    void solve(string& digits, int index, string& current,
               vector<string>& answer) {

        // If we have processed all digits
        if (index == digits.length()) {
            answer.push_back(current);
            return;
        }

        // Get letters corresponding to current digit
        string letters;

        if (digits[index] == '2') letters = "abc";
        else if (digits[index] == '3') letters = "def";
        else if (digits[index] == '4') letters = "ghi";
        else if (digits[index] == '5') letters = "jkl";
        else if (digits[index] == '6') letters = "mno";
        else if (digits[index] == '7') letters = "pqrs";
        else if (digits[index] == '8') letters = "tuv";
        else if (digits[index] == '9') letters = "wxyz";

        // Try every letter
        for (char ch : letters) {

            current.push_back(ch);

            solve(digits, index + 1, current, answer);

            // Backtrack
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> answer;

        if (digits.empty()) {
            return answer;
        }

        string current;

        solve(digits, 0, current, answer);

        return answer;
    }
};