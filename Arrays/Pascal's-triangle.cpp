class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        /* temp.push_back(1);
        ans.push_back(temp);
        if(numRows == 1) return ans;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows == 2) return ans;
        */
        for(long long int i = 0;i < numRows;i++) {
            vector<int> temp(i+1, 1);
            for(int j = 1;j < i;j++) {
                temp[j] = temp[j-1] * (i+1 - j)/j; 
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
