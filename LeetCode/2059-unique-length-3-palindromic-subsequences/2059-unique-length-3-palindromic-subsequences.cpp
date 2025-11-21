class Solution {

public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        vector<pair<int, int>> v(26, {-1, -1});
        for(char ch = 'a';ch <= 'z';ch++) {
            int firstocc = -1, lastocc = -1;
            for(int i = 0;i < n;i++) {
                if(s[i] == ch) {
                    if(firstocc != -1) lastocc = i;
                    else {
                        firstocc = i;
                        lastocc = i;
                    }
                }
                v[ch - 'a'] = {firstocc, lastocc};
            }
        }
        int cnt = 0;
        for(int i = 0;i < 26;i++) {
            int left = v[i].first, right = v[i].second;
            if(left == -1 or right == -1 or (left == right)) 
                continue;
            unordered_set<char> st;
            left += 1;
            while(left < right) {
                st.insert(s[left]);
                left++;
            }
            cnt += st.size();
        }
        return cnt;
    }
};