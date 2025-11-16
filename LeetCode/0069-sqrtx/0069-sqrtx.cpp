class Solution {
public:
    int mySqrt(int x) {
        
        int64_t lo = 1, hi = x, mid = 0, ans = 0;
        while((hi - lo) >= 0) {
            mid = lo + (hi - lo) / 2;
            if((mid * mid) <= x) {
                ans = mid;
                lo = mid + 1;
            }
            else 
                hi = mid - 1;
        }
        cout << ans << endl;
        return (int)ans;
    }
};

