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
        
        queue<string> q;
        q.push(s);
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            vis.insert(cur);
            string added = add(cur, a);
            string rotated = cur;
            rotate(rotated.begin(), rotated.begin()+b, rotated.end());
            if(vis.find(added) == vis.end()) {
                vis.insert(added);
                q.push(added);
            }
            if(vis.find(rotated) == vis.end()) {
                q.push(rotated);
                vis.insert(rotated);
            }
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