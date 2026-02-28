class Solution {
private:
    int mod = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        long long int num = 0;
        int shift = 0;
        for(long long int i = 1;i <= n;i++) {
            
            if((i & (i - 1)) == 0) shift++;
            
            num = (i | (num << shift))% mod ;
            // cout << num << endl;
        }
        return num;

    }
};