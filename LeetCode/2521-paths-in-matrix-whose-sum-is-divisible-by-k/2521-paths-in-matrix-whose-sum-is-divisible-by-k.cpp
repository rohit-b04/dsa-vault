class Solution {
private:
    int solve(vector<vector<int>>& grid, int& n, int& m, int i, int j, int& k, int sum, vector<vector<vector<int>>>& dp) {
        if(i >= n or j >= m) return 0;
        if(i == n - 1 and j == m - 1) {
            if((sum+grid[i][j]) % k == 0) return 1;
            return 0;
        }
        if(dp[i][j][sum%MOD] != -1) return dp[i][j][sum%MOD];
        int right = solve(grid, n, m, i, j + 1, k, (sum + grid[i][j])%k, dp);
        int down = solve(grid, n, m, i + 1, j, k, (sum + grid[i][j])%k, dp);
        dp[i][j][sum%MOD] = ((right + down) % MOD);
        return ((right + down) % MOD);
    }
public:
    int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        return solve(grid, n, m, 0, 0, k, 0, dp);
    }
};