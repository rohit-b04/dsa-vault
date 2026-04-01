class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> pref(n+1, 0);
        int maxi = INT_MIN;
        for(int i = 1;i <= n;i++) {
            pref[i] = pref[i-1] + gain[i-1];
            // maxi = max(maxi, pref[i-1]);
        }
        maxi = *max_element(pref.begin(), pref.end());
        // sort(pref.begin(), pref.end());
        return maxi;

    }
};