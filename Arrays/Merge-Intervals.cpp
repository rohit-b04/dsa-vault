class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for (const auto& interval : intervals) {
            // If the list of merged intervals is empty or no overlap, add the interval
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                // Overlapping intervals, merge them
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};
