class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        // Check if palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // Characters available for left half
        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int halfLen = n / 2;
        string left;

        // Check whether current prefix can be completed
        // into a palindrome > target.
        auto possible = [&]() {
            string temp = left;

            // Make the largest possible remaining left half
            for (int c = 25; c >= 0; c--) {
                temp += string(half[c], 'a' + c);
            }

            string pal = temp;

            if (n % 2)
                pal += mid;

            string rev = temp;
            reverse(rev.begin(), rev.end());
            pal += rev;

            return pal > target;
        };

        // Build left half greedily
        for (int pos = 0; pos < halfLen; pos++) {
            bool found = false;

            // Try smallest character first
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                half[c]--;
                left += char('a' + c);

                if (possible()) {
                    found = true;
                    break;
                }

                // Undo
                left.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }

        // Construct final palindrome
        string ans = left;

        if (n % 2)
            ans += mid;

        reverse(left.begin(), left.end());
        ans += left;

        return ans > target ? ans : "";
    }
};