class Solution {
public:
    bool judgeCircle(string moves) {
        int row = 0, col = 0;
        for(char ch: moves) {
            if(ch == 'R') row++;
            else if(ch == 'L') row--;
            else if(ch == 'U') col--;
            else col++;
        }
        if(row == 0 and col == 0) return true;
        return false;
    }
};