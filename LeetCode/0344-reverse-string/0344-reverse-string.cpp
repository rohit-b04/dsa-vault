class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0;i < n / 2;i++) {
            int j = n - i - 1;
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};