class Solution {
private:

    bool isValid(int row, int col, int gridSize) {
        return row >= 0 && row < gridSize && col >= 0 && col < gridSize;
    }

    int find_shortest_time(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> dist(grid.size(), vector<int>(grid.size(), 1e9));

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        int n = grid.size();

        while(!pq.empty()) {
            auto it = pq.top();
            int parentDistance = it.first;
            int row = it.second.first, col = it.second.second;

            pq.pop();
            

            for(int i = 0;i < 4;i++) {
                int newRow = drow[i] + row;
                int newCol = dcol[i] + col;

                if(isValid(newRow, newCol, n) && dist[newRow][newCol] == 1e9) {
                    dist[newRow][newCol] = max(parentDistance, grid[newRow][newCol]);
             
                    pq.push({dist[newRow][newCol], {newRow, newCol}});

                }

            }
        }
        
        return dist[n-1][n-1];
    }

public:
    
    int swimInWater(vector<vector<int>>& grid) {
        int shortestTime = find_shortest_time(grid);
        return shortestTime;
    }
};