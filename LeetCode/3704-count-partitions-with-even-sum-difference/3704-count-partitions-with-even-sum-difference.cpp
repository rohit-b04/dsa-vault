class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        prefix[0] = 0;
        for(int i = 0;i < n;i++) {
            prefix[i+1] = prefix[i] + nums[i];
        } 
        if(prefix[n] % 2 != 0) return 0;
        int cnt=0, total = prefix[n];
        for(int i = 1;i <= n-1;i++)
            if(prefix[i] % 2 == (total - prefix[i])%2) cnt++;
        return cnt;
    }
};