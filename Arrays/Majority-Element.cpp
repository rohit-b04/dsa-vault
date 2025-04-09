class Solution {
public:
  // Moore's Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int count = 0, candidate = 0;
        for(int i = 0;i < size;i++) {
            if(count == 0) {
                candidate = nums[i];
            }
            if(candidate == nums[i]) count++;
            else count--;
        }
        return candidate;
    }
};
