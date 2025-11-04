class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& color) {
        queue<int> q;
        vis[node] = 1;
        color[node] = 0;
        q.push(node);

        while(!q.empty()) {

            int val = q.front();
            q.pop();

            for(auto it: graph[val]) {
                if(color[it] == -1) {

                    color[it] = 1 - color[val];
                    q.push(it);

                }
                else if(color[it] == color[val]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> color(n, -1);

        for(int i = 0;i < n;i++) {
            if(color[i] == -1) {

                if(!bfs(i, graph, vis, color)) return false;
            }
        }
        return true;
    }
};