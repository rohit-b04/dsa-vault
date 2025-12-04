class Solution {
public:
    int countCollisions(string directions) {
        string s = directions;
        int n = s.size();
      
        int leftBoundary = 0;
        while (leftBoundary < n && s[leftBoundary] == 'L') {
            ++leftBoundary;
        }
      
        int rightBoundary = n - 1;
        while (rightBoundary >= 0 && s[rightBoundary] == 'R') {
            --rightBoundary;
        }
      
        int totalCarsInRange = rightBoundary - leftBoundary + 1;
        int stationaryCars = count(s.begin() + leftBoundary, 
                                   s.begin() + rightBoundary + 1, 'S');
      
        return totalCarsInRange - stationaryCars;
    }
};