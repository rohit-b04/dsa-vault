#include <vector>

class Solution {
private:
    bool check(std::vector<int>& stations, int r, long long k, long long target) {
        int n = stations.size();
        std::vector<long long> stations_ll(n);
        for(int i = 0; i < n; ++i) stations_ll[i] = stations[i];

        std::vector<long long> city_power(n);
        long long current_window_sum = 0;
        
        for (int i = 0; i <= r && i < n; ++i) {
            current_window_sum += stations_ll[i];
        }
        city_power[0] = current_window_sum;

        for (int i = 1; i < n; ++i) {
            int add_idx = i + r;
            int rem_idx = i - r - 1;
            if (add_idx < n) current_window_sum += stations_ll[add_idx];
            if (rem_idx >= 0) current_window_sum -= stations_ll[rem_idx];
            city_power[i] = current_window_sum;
        }

        long long k_used = 0;
        std::vector<long long> diff(n + 1, 0);
        long long current_addition_effect = 0;

        for (int i = 0; i < n; ++i) {
            current_addition_effect += diff[i];
            long long current_total_power = city_power[i] + current_addition_effect;
            
            if (current_total_power < target) {
                long long needed = target - current_total_power;
                k_used += needed;
                if (k_used > k) return false;
                
                current_addition_effect += needed;
                int end_effect_index = i + 2 * r + 1;
                if (end_effect_index <= n) {
                    diff[end_effect_index] -= needed;
                }
            }
        }
        
        return true;
    }

public:
    long long maxPower(std::vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long low = 0;
        long long high = 0;
        for(int s : stations) high += s;
        high += k;
        
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(stations, r, (long long)k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};