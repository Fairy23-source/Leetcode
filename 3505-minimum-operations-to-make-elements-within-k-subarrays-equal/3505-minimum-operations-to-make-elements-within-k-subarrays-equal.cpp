
class Solution {
    multiset<int> lo, hi;
    long long sumLo = 0, sumHi = 0;

    void balance() {
        int need = (lo.size() + hi.size() + 1) / 2;

        while (lo.size() > need) {
            int v = *lo.rbegin();
            lo.erase(prev(lo.end()));
            sumLo -= v;
            hi.insert(v);
            sumHi += v;
        }

        while (lo.size() < need) {
            int v = *hi.begin();
            hi.erase(hi.begin());
            sumHi -= v;
            lo.insert(v);
            sumLo += v;
        }
    }

    void add(int v) {
        if (lo.empty() || v <= *lo.rbegin()) {
            lo.insert(v);
            sumLo += v;
        } else {
            hi.insert(v);
            sumHi += v;
        }
        balance();
    }

    void remove(int v) {
        auto it = lo.find(v);

        if (it != lo.end()) {
            lo.erase(it);
            sumLo -= v;
        } else {
            it = hi.find(v);
            hi.erase(it);
            sumHi -= v;
        }

        balance();
    }

    long long getCost() {
        long long med = *lo.rbegin();

        return med * lo.size() - sumLo
             + sumHi - med * hi.size();
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(nums[i]);

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = getCost();
        }

        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i + 1][j];

                if (i + x <= n && dp[i + x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        cost[i] + dp[i + x][j - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};
