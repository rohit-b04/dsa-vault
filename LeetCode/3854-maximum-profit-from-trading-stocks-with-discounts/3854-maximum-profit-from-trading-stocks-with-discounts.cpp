#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, budget;
    vector<int> present, future;
    vector<vector<int>> tree;

    static constexpr long long NEG_INF = LLONG_MIN / 4;

    // Merge two knapsack DP arrays
    vector<long long> mergeDP(const vector<long long>& A,
                              const vector<long long>& B) {
        vector<long long> merged(budget + 1, NEG_INF);
        for (int i = 0; i <= budget; i++) {
            if (A[i] == NEG_INF) continue;
            for (int j = 0; j + i <= budget; j++) {
                if (B[j] == NEG_INF) continue;
                merged[i + j] = max(merged[i + j], A[i] + B[j]);
            }
        }
        return merged;
    }

    // Memoization map: (u, parent) -> {noDiscount, withDiscount}
    map<pair<int,int>, pair<vector<long long>, vector<long long>>> memo;

    pair<vector<long long>, vector<long long>> dp(int u, int parent) {
        auto key = make_pair(u, parent);
        if (memo.count(key)) return memo[key];

        vector<long long> noDiscount(budget + 1, 0);
        vector<long long> withDiscount(budget + 1, 0);

        for (int v : tree[u]) {
            if (v == parent) continue;
            auto [childNo, childWith] = dp(v, u);
            noDiscount = mergeDP(noDiscount, childNo);
            withDiscount = mergeDP(withDiscount, childWith);
        }

        vector<long long> newDp0 = noDiscount;
        vector<long long> newDp1 = noDiscount;

        // 1. Buy at full cost
        int fullCost = present[u];
        for (int b = fullCost; b <= budget; b++) {
            long long profit = future[u] - fullCost;
            newDp0[b] = max(newDp0[b],
                            withDiscount[b - fullCost] + profit);
        }

        // 2. Buy at half cost (discounted by parent)
        int halfCost = present[u] / 2;
        for (int b = halfCost; b <= budget; b++) {
            long long profit = future[u] - halfCost;
            newDp1[b] = max(newDp1[b],
                            withDiscount[b - halfCost] + profit);
        }

        return memo[key] = {newDp0, newDp1};
    }

    long long maxProfit(int n_,
                        vector<int>& present_,
                        vector<int>& future_,
                        vector<vector<int>>& hierarchy,
                        int budget_) {
        n = n_;
        present = present_;
        future = future_;
        budget = budget_;

        tree.assign(n, {});
        for (auto& e : hierarchy) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            tree[u].push_back(v);
        }

        auto result = dp(0, -1).first;
        return *max_element(result.begin(), result.end());
    }
};
