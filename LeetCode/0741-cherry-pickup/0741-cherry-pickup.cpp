class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int j, int x, int y, int n,
                vector<vector<vector<vector<int>>>>& dp) {
        if(j >= n or y >= n or x >= n or i >= n or grid[i][j] == -1 or grid[x][y] == -1) 
            return -1e8;
        if((i == n - 1 and j == n - 1)) {
            if(i == x and y == j) 
                return grid[i][j];
        }
        if(dp[i][j][x][y] != -1) return dp[i][j][x][y];
        int maxi = -1e8, ans = 0;
        int a = solve(grid, i + 1, j, x+1, y, n, dp);
        int b = solve(grid, i+1, j, x, y+1, n, dp) ;
        int c = solve(grid, i, j + 1, x+1, y, n, dp);
        int d = solve(grid, i, j+1, x, y+1, n, dp);
        
        if(i == x and j == y) ans += grid[i][j];
        else ans += grid[i][j] + grid[x][y];
        
        maxi = max({a, b, c, d}); 
        return dp[i][j][x][y] = ans + maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(n + 1, -1))));
        int res = solve(grid, 0, 0, 0, 0, grid.size(), dp);
        return max(0, res);
    }
};