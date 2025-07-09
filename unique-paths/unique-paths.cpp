class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int idx = 1; idx < m * n; idx++) {
            int i = idx / n, j = idx % n;
            int cur = 0;
            if (j > 0)
                cur += dp[i][j - 1];
            if (i > 0)
                cur += dp[i - 1][j];
            dp[i][j] = cur;
        }
        return dp[m - 1][n - 1];
    }
};