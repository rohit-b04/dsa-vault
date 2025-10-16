class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value, 0);
        for (int x : nums) {
            int r = ((x % value) + value) % value; 
            freq[r]++;
        }

        for (int i = 0; ; i++) {
            int r = i % value;
            if (freq[r] == 0) return i;
            freq[r]--;  
        }
    }
};
