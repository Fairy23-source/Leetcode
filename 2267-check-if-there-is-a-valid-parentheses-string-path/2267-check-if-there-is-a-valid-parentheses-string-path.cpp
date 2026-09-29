class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool dfs(vector<vector<char>>& grid, int i, int j, int balance) {

        // Out of bounds
        if (i >= m || j >= n)
            return false;

        // Update balance for current cell
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Balance cannot be negative
        if (balance < 0)
            return false;

        // Remaining cells cannot close all brackets
        int remaining = (m - 1 - i) + (n - 1 - j);

        if (balance > remaining)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1)
            return balance == 0;

        // Already calculated
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        // Move right or down
        bool right = dfs(grid, i, j + 1, balance);
        bool down = dfs(grid, i + 1, j, balance);

        return dp[i][j][balance] = (right || down);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Total path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // Start must be '('
        if (grid[0][0] == ')')
            return false;

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(m + n, -1)
        ));

        return dfs(grid, 0, 0, 0);
    }
};