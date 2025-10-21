class Solution {

public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> frequencyMap;
      
        map<int, int> rangeDifference;
        for (int num : nums) {
            frequencyMap[num]++;
          
            rangeDifference[num];
          
            rangeDifference[num - k]++;
            rangeDifference[num + k + 1]--;
        }
      
        int maxResult = 0;
        int currentRangeCount = 0;  
      
        for (const auto& [position, difference] : rangeDifference) {
            currentRangeCount += difference;
          
            maxResult = max(maxResult, min(currentRangeCount, frequencyMap[position] + numOperations));
        }
      
        return maxResult;
    }
};