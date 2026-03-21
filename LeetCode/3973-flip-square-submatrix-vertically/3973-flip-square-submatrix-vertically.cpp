class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int row = x; row < x + k / 2; row++) {
            // Calculate the corresponding row from the bottom to swap with
            int mirrorRow = x + k - 1 - (row - x);
          
            // Swap elements in all columns of the current row with the mirror row
            for (int col = y; col < y + k; col++) {
                swap(grid[row][col], grid[mirrorRow][col]);
            }
        }
      
        return grid;

    }
};