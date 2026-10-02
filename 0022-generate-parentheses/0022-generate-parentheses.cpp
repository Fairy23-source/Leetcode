class Solution {
public:

    void solve(int n, int open, int close,
               string current, vector<string>& answer) {

        // If we have used all parentheses
        if (current.length() == 2 * n) {
            answer.push_back(current);
            return;
        }

        // We can add '(' if we still have some left
        if (open < n) {
            solve(n, open + 1, close,
                  current + "(", answer);
        }

        // We can add ')' only if there is an unmatched '('
        if (close < open) {
            solve(n, open, close + 1,
                  current + ")", answer);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> answer;

        solve(n, 0, 0, "", answer);

        return answer;
    }
};