class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int node) {
        // base case...
        if(vis[node] == 1) return;
        vis[node] = 1;
        for(int i = 0;i < isConnected.size();i++) {
            if(isConnected[node][i] and !vis[i]) 
                dfs(isConnected, vis, i);
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n+1, 0);
        int count = 0;
        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                dfs(isConnected, vis, i);
                count++;
                vis[i] = 1;
            }

        }
        return count;
    }
};