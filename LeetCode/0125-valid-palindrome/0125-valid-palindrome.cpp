class Solution {
private:
    string split(string& s) {
        string ans = "";
        for(int i = 0;i < s.size();i++) {
            if(!isalnum(s[i])) {
                continue;
            }    
            ans.push_back(s[i]);
        }
        return ans;
    }
public:
    bool isPalindrome(string s) {
        
        string str = split(s);
        for(int i = 0;i < str.size();i++) 
            if(str[i] < '0' or str[i] >'9') str[i] = tolower(str[i]);
        for(int i = 0;i < str.size()/2;i++) {
            int j = str.size() - i - 1;
            if(str[i] != str[j]) return false;
        }
        return true;
    }
};