class Solution {
public:
    double mul(double x, int n) {
        long nn = n;
        double ans = 1.0;
        if(nn < 0) nn = -1 * nn;
        while(nn > 0) {
            if(nn % 2 == 1) {
                ans = ans * x;
                nn = nn -1;
            }
            else {
                x = x * x; 
                nn = nn / 2;
            }
    }
    if(n < 0) return double(1.0) / double(ans);
    return double(ans);
    }
    double myPow(double x, int n) {
        double ans = mul(x,n);
        return ans;
    }
};
