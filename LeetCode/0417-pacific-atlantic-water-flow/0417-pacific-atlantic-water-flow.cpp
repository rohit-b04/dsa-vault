class Solution {
private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, pair<int, int>>>& q, vector<vector<int>>& vis) {
        vector<vector<int>> ans;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        int n = heights.size(), m = heights[0].size();
        
        // unordered_set<pair<int, int>> res;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0;i < size;i++) {
                
                int h = q.front().first;
                int row = q.front().second.first, col = q.front().second.second;
                q.pop();
                ans.push_back({row, col});

                for(int k = 0;k < 4;k++) {
                    int nrow = row + drow[k], ncol = col + dcol[k];
                    if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and h <= heights[nrow][ncol] and !vis[nrow][ncol]) {
                        q.push({heights[nrow][ncol], {nrow, ncol}});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        // return ans;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        queue<pair<int, pair<int, int>>> pac, atl;

        vector<vector<int>> visPac(n + 1, vector<int>(m + 1, 0)), visAtl(n + 1, vector<int>(m + 1, 0));
        for(int i = 0;i < n;i++) {
            visPac[i][0] = 1;
            visAtl[i][m - 1] = 1;
            pac.push({heights[i][0], {i, 0}});
            atl.push({heights[i][m - 1], {i , m - 1}});
        }

        for(int i = 0;i < m;i++) {
            if(!visPac[0][i]) pac.push({heights[0][i], {0, i}});
            visPac[0][i] = 1;
            if(!visAtl[n-1][i]) atl.push({heights[n - 1][i], {n - 1, i}});
            visAtl[n - 1][i] = 1;
        }
        bfs(heights, pac, visPac);
        bfs(heights, atl, visAtl);
        vector<vector<int>> res;
        
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(visPac[i][j] and visAtl[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};