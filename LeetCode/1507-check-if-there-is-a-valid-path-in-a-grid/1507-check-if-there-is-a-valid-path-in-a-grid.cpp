class Solution {
private:
    set<int> right = {1, 4, 6}, left = {1, 3, 5}, up = {2, 5, 6}, down = {2, 3, 4};

    bool hasValidPath(vector<vector<int>>& grid, int n, int m, vector<vector<bool>>& vis) {
        int rows = grid.size(), cols = grid[0].size();

        if(n < 0 || m < 0 || n >= rows || m >= cols) return false;
        if(vis[n][m]) return false;
        if(n == rows-1 && m == cols-1) return true;

        vis[n][m] = true;

        int val = grid[n][m];

        // LEFT
        if((val == 1 || val == 3 || val == 5) && m-1 >= 0 &&
           right.contains(grid[n][m-1]) &&
           hasValidPath(grid, n, m-1, vis)) return true;

        // RIGHT
        if((val == 1 || val == 4 || val == 6) && m+1 < cols &&
           left.contains(grid[n][m+1]) &&
           hasValidPath(grid, n, m+1, vis)) return true;

        // UP
        if((val == 2 || val == 5 || val == 6) && n-1 >= 0 &&
           down.contains(grid[n-1][m]) &&
           hasValidPath(grid, n-1, m, vis)) return true;

        // DOWN
        if((val == 2 || val == 3 || val == 4) && n+1 < rows &&
           up.contains(grid[n+1][m]) &&
           hasValidPath(grid, n+1, m, vis)) return true;

        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        return hasValidPath(grid, 0, 0, vis);
    }
};