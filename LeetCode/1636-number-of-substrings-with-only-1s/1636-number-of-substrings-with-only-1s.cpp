class Solution {
public:
    int numSub(string s) {
        int cur = 0, prev = -1, total = 0;
        int MOD = 1e9 + 7;
        for(int i = 0;i < s.size();i++) {
            if(s[i] == '1') {
                cur++;
            }
            else {
                int64_t sum = (int64_t)cur * (cur + 1) / 2;
                total = (sum + total) % MOD;
                cur = 0;
            }
        }
        if(cur != 0) {
            int64_t sum = (int64_t)cur * (cur + 1) / 2;
            total = (sum + total) % MOD;
            cur = 0;
        }
        return total;
    }
};