class Solution {
private:
    bool isPossible(vector<int>& nums, int k) {
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
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int lo = 1, hi = nums.size() - 1;
        int mid = 0, ans = 0;
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(isPossible(nums, mid)) {
                ans = mid;
                lo = mid + 1;
            }
            else 
                hi = mid - 1;
        }
        return ans;
    }
};