class Solution {

public:
    int superEggDrop(int k, int n) {
        if(k == 1) 
            return n;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        for(int i = 1;i <= n;i++) 
            dp[1][i] = i;
        for(int j = 1;j <= k;j++)
            dp[j][0] = 0;
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[1][1] = 1;
        for(int i = 2;i <= k;i++) {
            for(int j = 1;j <= n;j++) {
                int mini = 1e8;
                int lo = 1, hi = j, mid = 0;
                while(lo <= hi) {
                    mid = lo + (hi - lo) / 2;
                    int broken = dp[i-1][mid-1];
                    int notBroken = dp[i][j - mid];
                    if(broken < notBroken) 
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                    mini = min(mini, 1 + max(broken, notBroken));
                }
                dp[i][j] = mini;
            }
        }
        return dp[k][n];
    }
};