class Solution {

public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        const int MOD = 12345;
        int rows = grid.size();
        int cols = grid[0].size();
      
        vector<vector<int>> result(rows, vector<int>(cols));
      
        long long suffixProduct = 1;
        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                result[row][col] = suffixProduct;
                suffixProduct = (suffixProduct * grid[row][col]) % MOD;
            }
        }
      
        long long prefixProduct = 1;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                result[row][col] = (result[row][col] * prefixProduct) % MOD;
                prefixProduct = (prefixProduct * grid[row][col]) % MOD;
            }
        }
      
        return result;

    }
};