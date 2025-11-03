class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, false);
        int maxCycle = -1;
        for(int i = 0;i < n;i++) {
            int curNode = i;
            vector<int> path;
            if(vis[curNode]) continue;
            while(curNode != -1 and !vis[curNode]) {
                vis[curNode] = true;
                path.push_back(curNode);
                curNode = edges[curNode];
            }
            if(curNode == -1) continue;
            for(int j = 0;j < path.size();j++) {
                if(curNode == path[j]) {
                    int ans = path.size() - j;
                    maxCycle = max(maxCycle, ans);
                    break;
                }
            }
        }
        return maxCycle;
    }
};