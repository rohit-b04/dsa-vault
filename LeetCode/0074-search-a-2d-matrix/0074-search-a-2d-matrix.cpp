class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row, col;
        int low = 0, high = matrix.size() * matrix[0].size() - 1;
        int mid = 0;
        while(low <= high) {
            mid = low + (high - low) / 2;
            row = mid / matrix[0].size();
            col = mid % matrix[0].size();
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};