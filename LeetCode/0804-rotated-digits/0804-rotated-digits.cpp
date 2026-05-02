class Solution {
public:
    int rotatedDigits(int n) {
        bool isGood = false, isPartGood = false;
        int count = 0;
        for(int i = 1;i <= n;i++) {
            int num = i, dig;
            isGood = false;
            isPartGood = false;
            while(num) {
                dig = num % 10;
                if(dig == 2 || dig == 5 || dig == 6 || dig == 9) isGood = true;
                else if((dig == 1 || dig == 0 || dig == 8)) {
                    isPartGood = true;
                } 
                else {
                    isGood = false;
                    break;
                }
                num /= 10;
            }
            if(isPartGood) {
                cout << i << endl;
                if(isGood)
                    count++;
            }
            else if(isGood) {
                // cout << i << endl;
                count++;
            }
        }
        return count;
    }
};