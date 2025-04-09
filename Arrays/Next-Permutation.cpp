class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakPoint = -1;
       // int i = nums.size()-2;
        for(int i = nums.size() - 2;i >= 0;i--) {
            if(nums[i] < nums[i+1])
            {
              breakPoint = i;
              break;  
            } 
            
        }
        if(breakPoint == -1) 
        {
            reverse(nums.begin(), nums.end());
        }
        else {
            for(int i = nums.size()-1;i > breakPoint;i--) {
                if(nums[i] > nums[breakPoint]) 
                {    
                    swap(nums[breakPoint], nums[i]);
                    break;
                }
            }
            reverse(nums.begin() + breakPoint + 1, nums.end());
            
        }
        for(int i = 0;i < nums.size();i++) cout << nums[i] << " ";
    }
};
