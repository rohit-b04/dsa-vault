class Solution {
private:
    int solve(int e, int f, vector<vector<int>> &dp) {
        if(e == 1 || f == 0 || f == 1) 
            return f;
        if(dp[e][f] != -1) 
            return dp[e][f];
        int mini = 1e8;

        int lo = 0, hi = f, mid = 0;
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int broken = solve(e - 1, mid - 1, dp);
            int notBroken = solve(e, f - mid, dp);
            if(broken < notBroken) 
                lo = mid + 1;
            else 
                hi = mid - 1;
            mini = min(mini, 1 + max(broken, notBroken));
        }
        
        return dp[e][f] = mini;
    }
public:
    int superEggDrop(int k, int n) {
        if(k == 1) 
            return n;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};