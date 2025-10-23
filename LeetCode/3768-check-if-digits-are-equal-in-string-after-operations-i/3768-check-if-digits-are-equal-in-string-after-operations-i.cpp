class Solution {
public:
    bool hasSameDigits(string s) {
        string str = s;
        int i = 0;
        while(i < str.size()-1) {
            str[i] = (((str[i]-'0') + (str[i + 1] - '0')) % 10) + '0';
            // cout << str[i] << endl;
            i++;
            if(i == str.size()-1) {
                i = 0;
                str.pop_back();
                if(str.size() == 2) break;
            }
        }
        // cout << str << endl;
        return str[0] == str[1];
    }
};