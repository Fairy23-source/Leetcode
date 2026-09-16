class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        vector<vector<int>> g(n + 1, vector<int>(k + 1));

        f[1][0] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {

                // Don't end a segment here
                f[i][j] = (f[i - 1][j] + g[i - 1][j]) % MOD;

                // Continue previous state
                g[i][j] = g[i - 1][j];

                if (j > 0) {
                    // Start/end a new segment
                    g[i][j] = (g[i][j] + f[i - 1][j - 1]) % MOD;

                    // Continue a segment
                    g[i][j] = (g[i][j] + g[i - 1][j - 1]) % MOD;
                }
            }
        }

        return (f[n][k] + g[n][k]) % MOD;
    }
};