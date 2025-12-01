class Solution {
private:
    bool isPossible(vector<int>& batteries, int n, long long mins) {
        long long total = 0;
        for(int& bat: batteries)
            total += min(mins, static_cast<long long>(bat));
        return total >= (n * mins);
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        using ll = long long;
        ll totalmins = 0;
        for(int& bat: batteries) 
            totalmins += bat;

        ll lo = 0, hi = totalmins, mid = 0, ans = 0;
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(isPossible(batteries, n, mid)) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};