class Solution {
private:
    long long solve(vector<vector<int>>& adj, int node, int parent, vector<int>& values, int& k, long long& ans) {
        long long sum = values[node];

        for(int& child: adj[node]) {
            if(child != parent) {
                sum += solve(adj, child, node, values, k, ans);
            }
        }
        
        if(sum % k == 0) ans++;
        
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        long long ans = 0;
        vector<vector<int>> adj(n+1);
        for(auto& it: edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n + 1, 0);
        long long sol = solve(adj, 0, -1, values, k, ans);
        return ans;
    }
};