class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> arr;

        for(auto &row : grid) {
            for(int val : row) {
                arr.push_back(val);
            }
        }

        // Feasibility check
        int rem = arr[0] % x;
        for(int val : arr) {
            if(val % x != rem) return -1;
        }

        sort(arr.begin(), arr.end());

        int med = arr[arr.size() / 2];
        int ans = 0;

        for(int val : arr) {
            ans += abs(val - med) / x;
        }

        return ans;
    }
};