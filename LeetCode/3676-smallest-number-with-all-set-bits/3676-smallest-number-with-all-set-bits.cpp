class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;
        while(n) {
            ans |= 1;
            // cout << ans << endl;
            ans = ans << 1;
            // cout << ans << endl;
            n = n >> 1;
        }
        ans = ans >> 1;
        return ans;
    }
};