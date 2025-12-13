class Solution {
private:
    bool isValid(string s) {
        for(char ch: s) {
            if(isalnum(ch) or ch == '_') continue;
            else return false;
        }
            
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ans;
        priority_queue<pair<string, string>, vector<pair<string, string>>, 
                        greater<pair<string, string>>> pq;
        for(int i = 0;i < code.size();i++) {
            string bline = businessLine[i];
            if(!isValid(code[i]) or code[i].size() == 0) 
                continue;
            if((bline == "electronics"||bline == "grocery"||
            bline == "pharmacy"||bline == "restaurant") and isActive[i]) 
                pq.push({bline, code[i]});
        }
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};