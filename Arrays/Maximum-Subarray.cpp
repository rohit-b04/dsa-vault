class Solution {
public:
  // Kadane's Algorithm
    int maxSubArray(vector<int>& nums) {
        int sum = 0, n = nums.size(), maxSum = INT_MIN;
        for(int i = 0;i < n; i++) {
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};
