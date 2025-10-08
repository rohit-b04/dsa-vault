class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> pairs(n, 0);
        vector<pair<int,int>> spellsWithIdx;
        
        for(int i = 0;i < n;i++) 
            spellsWithIdx.push_back({spells[i], i});

        sort(spellsWithIdx.begin(), spellsWithIdx.end());
        sort(potions.begin(), potions.end());

        for(int i = 0;i < n;i++) {
            long long spell = spellsWithIdx[i].first;
            double target = (double)success / spell;

            int lo = 0, hi = m - 1, ans = m;

            while(lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if(potions[mid] >= target) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            pairs[spellsWithIdx[i].second] = m - ans;
        }
        return pairs;
    }
};
