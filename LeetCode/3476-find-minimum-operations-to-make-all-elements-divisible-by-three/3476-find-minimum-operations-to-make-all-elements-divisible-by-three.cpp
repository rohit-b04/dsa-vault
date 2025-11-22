class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op = 0;
        for(int num: nums) {
            if((num + 2) % 3 == 0) op++;
            else if((num - 2) % 3 == 0) op++;
        }
        return op;
    }
};