class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcount = 0, rcount = 0;
        for(char ch: moves) {
            if(ch == 'L') lcount++;
            else if(ch == 'R')rcount++;
        }
        if(lcount <= rcount) return (rcount + (moves.size() - (rcount + lcount))) - lcount;
        return (lcount + (moves.size() - (rcount + lcount))) - rcount;
    }
};