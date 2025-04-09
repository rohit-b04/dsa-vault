class Solution {
public:
    bool binSearch(vector<int> row, int size, int target) {
        int low = 0, high = size-1;
        int mid = (low+high)/2;
        //cout<< row[3];
        while(low <= high) {
            if(row[mid] == target) return true;
            else if(row[mid] > target) high--;
            else low++;
            mid = (low+high)/2;
        }
        return false;
    } 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n =  matrix[0].size();
        vector<int> rows(n, 0);
        for(auto row: matrix) {
            rows = row;
            if(binSearch(rows, n, target)) return true;
        }
        return false;
    }
};
