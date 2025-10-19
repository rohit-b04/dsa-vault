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
    void dfs(string& s, int a, int b, set<string>& vis) {
        
        string added = add(s, a);
        string rot = s;
        rotate(rot.begin(), rot.begin()+b,rot.end());
        if(vis.find(rot) == vis.end()) {
            vis.insert(rot);
            dfs(rot, a, b, vis);
        }
        if(vis.find(added) == vis.end()) {
            vis.insert(added);
            dfs(added, a, b, vis);
        }
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> vis;
        dfs(s, a, b, vis);
        string mini = *vis.begin();
        return mini;

    }
};