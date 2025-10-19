class Solution {
private:
    string add(string& s, int a) {
        string ans = s;
        for(int i = 0;i < s.size();i++) {
            if(i % 2 ==1) {
                int toInt = ans[i] - '0';
                toInt = (toInt + a) % 10;
                ans[i] = '0' + toInt;
            } 
                
        }
        return ans;
    }
    // string rotate(string& s, int b) {

    // }
    void dfs(string& s, int a, int b, set<string>& vis, vector<string>& ans) {
        
        // for(int i = 0;i < s.size();i++) {
            string added = add(s, a);
            // ans.push_back(added);
            // vis.insert(added);
            string rot = s;
            rotate(rot.begin(), rot.begin()+b,rot.end());
            // ans.push_back(rotate);
            // vis.insert(rotate);
            if(vis.find(rot) == vis.end()) {
                vis.insert(rot);
                dfs(rot, a, b, vis, ans);
            }
            if(vis.find(added) == vis.end()) {
                vis.insert(added);
                dfs(added, a, b, vis, ans);
            }
        // }
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> vis;
        vector<string> ans;
        dfs(s, a, b, vis, ans);
        string mini = *vis.begin();
        return mini;

    }
};