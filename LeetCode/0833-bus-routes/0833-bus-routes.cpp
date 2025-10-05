class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target) 
            return 0;
        int maxi = -1;
        for(auto& row: routes) 
            maxi = max(maxi, *max_element(row.begin(), row.end()));

        unordered_map<int, vector<int>> mp;
      
        for(int i = 0;i < routes.size();i++) 
            for(auto& it: routes[i])
                mp[it].push_back(i);
        
        queue<int> q;
        vector<int> visBus(routes.size(), 0);
        vector<int> vis(maxi + 1, 0);
        for(auto& it: mp[source]){
            q.push(it);
            visBus[it] = 1;
            vis[source] = 1;
        }
        
        int cnt = 0, curBus;
            
        while(!q.empty()) {
            
            int size = q.size();
            cnt++;
            for(int i = 0;i < size;i++) {
                curBus = q.front();
                q.pop();
                
                for(auto& it: routes[curBus]) {
                    if(it == target) 
                        return cnt;
                    if(!vis[it]) {
                        vis[it] = 1;
                        for(auto& j: mp[it]) {
                            if(!visBus[j]) {
                                q.push(j);
                                visBus[j] = 1;
                            }
                        }
                    } 
                }
            }
        }
        return -1;
    }
};