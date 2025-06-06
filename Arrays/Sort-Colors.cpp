class Solution {
public:
  // Dutch National Flag Algorithm
    void sortColors(vector<int>& nums) {
        int n = nums.size(), low = 0, mid = 0;
        int high = n - 1;
        while(mid <= high && low <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) mid++;
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        for(int i = 0;i < n;i++) cout << nums[i] << " ";
    }
};
