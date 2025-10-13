class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);
        string prev = words[0];
        for(int i = 1;i < n;i++) {
            string cur = words[i];
            prev = ans.back();
            unordered_map<char, int> mp;
            if(prev.size() != cur.size()) {
                ans.push_back(cur);
                continue;
            }
            for(int j = 0;j < prev.size();j++) {
                mp[prev[j]]++;
            }
            for(int j = 0;j < cur.size();j++) {
                mp[cur[j]]--;
            }
            bool isAnagram = true;
            for(auto& it: mp) {
                if(it.second != 0) {
                    isAnagram = false;
                    break;
                }
            }
            if(isAnagram) continue;
            ans.push_back(cur);
        }
        return ans;
    }
};