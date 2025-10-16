class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto& num: nums) 
            mp[num]++;
        priority_queue<pair<int, int>> pq;

        for(auto& it: mp) 
            pq.push({it.second, it.first});

        vector<int> ans;
        while(k) {
            int i = pq.top().second;
            pq.pop();
            ans.push_back(i);
            k--;
        }
        return ans;
    }
};