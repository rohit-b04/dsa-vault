class Solution {
public:
    int nextBeautifulNumber(int n) {
        long long num = 0, dig = 0;
        for(long long i = n+1;i <= 1e9;i++) {
            num = i;
            dig = 0;
            vector<int> v(10, 0);
            while(num) {
                dig = num % 10;
                v[dig]++;
                num /= 10;
            }
            bool isAns = true;
            num = i;
            while(num) {
                dig = num % 10;
                if(dig !=  v[dig]) {
                    isAns = false;
                    break;
                }
                num /= 10;
            }
            if(isAns) return i;
        }
        return 0;
    }
};