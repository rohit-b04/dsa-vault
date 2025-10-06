class Solution {
private:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if(i > j) return 0;
        int maxi = -1e8;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i;k <= j;k++) {
            int cost = (nums[i-1] * nums[k] * nums[j+1]) +
                    solve(nums, i, k-1, dp) + solve(nums, k+1, j, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(nums, 1, n, dp);
    }
};