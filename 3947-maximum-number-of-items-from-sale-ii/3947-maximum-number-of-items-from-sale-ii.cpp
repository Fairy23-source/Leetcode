
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Count items having each factor
        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        // Calculate how many different items each factor can unlock
        vector<int> gain(n + 1, 0);

        for (int factor = 1; factor <= n; factor++) {
            for (int multiple = factor; multiple <= n; multiple += factor) {
                gain[factor] += freq[multiple];
            }

            // Exclude the item itself
            gain[factor]--;
        }

        // Sort items by price
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remainingBudget = budget;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            // Buying this item for 2 copies must be better
            // than buying 2 cheapest items separately.
            if (2LL * price > 2LL * minPrice + price) {
                break;
            }

            // Only gain[factor] purchases can provide
            // distinct free items.
            int maxDiscounted = gain[factor];

            if (maxDiscounted == 0)
                continue;

            long long count = min(
                (long long)maxDiscounted,
                remainingBudget / price
            );

            ans += 2LL * count;
            remainingBudget -= count * price;
        }

        // Use remaining budget to buy cheapest items
        ans += remainingBudget / minPrice;

        return (int)ans;
    }
};
