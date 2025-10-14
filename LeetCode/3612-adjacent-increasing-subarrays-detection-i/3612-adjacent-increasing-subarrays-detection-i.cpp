class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int maxValidLength = 0; 
        int previousLength = 0;       
        int currentLength = 0;        
        int n = nums.size();
      
        for (int i = 0; i < n; ++i) {
            ++currentLength;
            if (i == n - 1 || nums[i] >= nums[i + 1]) {
                maxValidLength = max({maxValidLength, 
                                     currentLength / 2, 
                                     min(previousLength, currentLength)});
              
                previousLength = currentLength;
                currentLength = 0;
            }
        }
        return maxValidLength >= k;
    }
};