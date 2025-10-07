class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);

        set<int> dryDays;
        unordered_map<int, int> full;
        for(int i = 0;i < n;i++) {
            if(rains[i] == 0) { 
                dryDays.insert(i);
                ans[i] = 1;
            }    
            else {
                int lake = rains[i];
                if(full.find(lake) != full.end()) {
                    auto it = dryDays.upper_bound(full[lake]);
                    if(it == dryDays.end()) return {};
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                full[lake] = i;
                ans[i] = -1;
            }
        }
        return ans;
    }
};