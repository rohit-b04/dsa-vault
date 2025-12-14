class Solution {
public:
    const int mod = 1e9+7;
    vector<int> dp;
    int totalSeats;
    int numberOfWays(string corridor) {
        totalSeats = 0;
        for (auto c : corridor)
            if (c == 'S')
                totalSeats++;
        if (totalSeats%2)
            return 0;
        dp.resize(corridor.length(), -1);
        return numberOfWays(corridor, 0, 0);
    }
    int numberOfWays(string& corridor, int i, int seats) {
        if (i == corridor.length())
            return 0;
        
        int& ret = dp[i];
        if (ret != -1)
            return ret;
        
        ret = 0;
        if (corridor[i] == 'S') {
            seats++;
            if (seats == totalSeats)
                return ret = 1;
            if (seats % 2 == 0) {
                while (i+1 < corridor.length() and corridor[i+1] == 'P') {
                    ret += numberOfWays(corridor, i+1, seats);
                    ret %= mod;
                    i++;
                }
            }
        }
        ret += numberOfWays(corridor, i+1, seats);
        ret %= mod;
        return ret;
    }
};