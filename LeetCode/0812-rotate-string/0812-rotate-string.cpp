class Solution {

public:
    
    bool rotateString(string s, string goal) {

        return (s + s).contains(goal) and goal.size() == s.size();
    }
};