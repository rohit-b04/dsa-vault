class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total = 0;
        for(int num: nums) 
            total += num;
        return total % k;   
    }
};