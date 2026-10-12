
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> bits(31, 0);

        for (int x : nums) {
            for (int i = 0; i < 31; i++) {
                if (x & (1 << i)) {
                    bits[i]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int j = 0; j < 31; j++) {
                if (bits[j] > 0) {
                    x |= (1LL << j);
                    bits[j]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};
