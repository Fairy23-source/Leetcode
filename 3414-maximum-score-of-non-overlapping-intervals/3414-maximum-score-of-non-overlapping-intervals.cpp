class Solution {
public:
    struct State {
        long long weight;
        vector<int> indices;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting position
        sort(a.begin(), a.end());

        // Store start positions for binary search
        vector<long long> starts(n);
        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }

        // dp[i][k] = best answer starting from i, choosing at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Option 1: Skip current interval
                State skip = dp[i + 1][k];

                // Find first interval with start > current end
                int next = upper_bound(
                    starts.begin(),
                    starts.end(),
                    a[i][1]
                ) - starts.begin();

                // Option 2: Take current interval
                State take = dp[next][k - 1];
                take.weight += a[i][2];
                take.indices.push_back((int)a[i][3]);

                sort(take.indices.begin(), take.indices.end());

                // Choose better answer
                if (take.weight > skip.weight ||
                    (take.weight == skip.weight &&
                     take.indices < skip.indices)) {
                    dp[i][k] = take;
                } else {
                    dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].indices;
    }
};