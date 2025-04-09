class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        int ans = -1, n = nums.size();
        for(int i = 0;i < nums.size();i++) {
            temp[nums[i] % n]++;
            if(temp[nums[i] % n] >= 2) {
                ans = nums[i];
                break;
            }
        } 
        return ans;
    }
};
