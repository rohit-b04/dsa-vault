class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        int n = colors.size();
      
        for (int groupStart = 0, groupEnd = 0; groupStart < n; groupStart = groupEnd) {
            groupEnd = groupStart;
            int groupSum = 0;     
            int maxTime = 0;      
          
            while (groupEnd < n && colors[groupEnd] == colors[groupStart]) {
                groupSum += neededTime[groupEnd];
                maxTime = max(maxTime, neededTime[groupEnd]);
                ++groupEnd;
            }
          
            if (groupEnd - groupStart > 1) {
                totalCost += groupSum - maxTime;
            }
        }
      
        return totalCost;
    }
};