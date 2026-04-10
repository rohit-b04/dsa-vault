class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int n = nums.size(), ans = n * n * n;
        if(n < 3) return -1;
        for(int i = 0;i < n-2;i++) {
            for(int j = i+1;j < n-1;j++) {
                for(int k = j+1;k < n;k++) {
                    if(nums[i] == nums[j] and nums[j] == nums[k]) 
                        ans = min(abs(i - j) + abs(j - k) + abs(k - i), ans);
                }
            }
        }
        if(ans == (n * n * n)) return -1;
        return ans;
    }
};