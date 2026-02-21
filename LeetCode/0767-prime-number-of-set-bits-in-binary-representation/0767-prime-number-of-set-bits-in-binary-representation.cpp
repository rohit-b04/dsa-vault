class Solution {
private:
    int getSetBitsCount(int num) {
        int count = 0;

        while(num > 0) {
            if(num & 1) count++;
            num = num >> 1;
        }
        return count;
    }
    bool isPrime(int n) {
        
        for(int i = 2;i < n;i++) {
            if(n % i == 0 and n != 2) return false;
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int setBitsCnt = 0, count = 0;
        for(int i = left;i <= right;i++) {
            setBitsCnt = getSetBitsCount(i);
            if(setBitsCnt > 1 and isPrime(setBitsCnt)) {
                count++;
            }
        }
        return count;
    }
};