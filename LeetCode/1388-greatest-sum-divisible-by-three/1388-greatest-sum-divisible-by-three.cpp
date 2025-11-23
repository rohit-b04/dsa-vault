class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, INT_MIN);
        dp[0] = 0;

        for(int x : nums) {
            vector<int> ndp = dp;
            int m = x % 3;
            for(int r = 0; r < 3; r++) {
                int nr = (r + m) % 3;
                ndp[nr] = max(ndp[nr], dp[r] + x);
            }
            dp = ndp;
        }
        return dp[0];
    }
};
