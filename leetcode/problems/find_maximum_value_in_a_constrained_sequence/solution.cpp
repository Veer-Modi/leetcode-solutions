class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions,
                   vector<int>& diff) {
        auto zorimnacle = restrictions;
        vector<long long> maxA(n, LLONG_MAX);
        maxA[0] = 0;
        for (auto& r : restrictions) {
            maxA[r[0]] = min(maxA[r[0]], (long long)r[1]);
        }
        for (int i = 1; i < n; i++) {
            maxA[i] = min(maxA[i], maxA[i - 1] + diff[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            maxA[i] = min(maxA[i], maxA[i + 1] + diff[i]);
        }
        return *max_element(maxA.begin(), maxA.end());
    }
};