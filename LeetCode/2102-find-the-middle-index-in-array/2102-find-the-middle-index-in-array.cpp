class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n+2, 0);
        for(int i = 1;i <= n;i++) {
            p[i] = p[i-1] + nums[i-1];
        }
        int mididx = -1;
        for(int i = 1;i <= n;i++) {
            int right = p[n] - p[i];
            int left = p[i-1];
            if(left == right) return i-1;
        }
        cout << "out " << endl;
        return -1;
    }
};