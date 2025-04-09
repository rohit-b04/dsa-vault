class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        long long int col = grid[0].size(), row = grid.size();
        long long int n = col * row;
        long long int sn = n * (n + 1) / 2;
        long long int s2n = (n * (n + 1) * (2 * n + 1)) / 6;
        long long int s = 0, s2 = 0;
        for(int i = 0;i < row;i++) {
            for(int j = 0;j < col;j++) {
                s += grid[i][j];
                s2 +=grid[i][j] * grid[i][j];
            }
        }
        long long int eq1 = s - sn;
        long long int eq2 = s2 - s2n;
        eq2 = eq2 / eq1;
        long long int x = (eq1 + eq2) / 2;
        long long int y = eq2 - x;
        ans.push_back(x);
        ans.push_back(y);
        return ans;

    }
};
