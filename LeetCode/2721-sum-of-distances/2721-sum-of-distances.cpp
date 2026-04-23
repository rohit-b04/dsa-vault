class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);
        
        for(auto& [val, indices] : mp) {
            int m = indices.size();
            vector<long long> pref(m+1, 0);
            for(int i = 0; i < m; i++)
                pref[i+1] = pref[i] + indices[i];
            
            for(int i = 0; i < m; i++) {
                long long idx = indices[i];
                long long right = (pref[m] - pref[i+1]) - idx * (m - i - 1);
        
                long long left = idx * i - pref[i];
                ans[indices[i]] = left + right;
            }
        }
        return ans;
    }
};