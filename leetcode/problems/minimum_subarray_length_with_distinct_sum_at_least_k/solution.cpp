class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int l = 0;
        int sum = 0;
        int len = INT_MAX;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == 1) {
                sum += nums[i];
            }
            while (sum >= k) {
                len = min(len, i - l + 1);
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    sum -= nums[l];
                }
                l++;
            }
        }
        return len == INT_MAX ? -1 : len;
    }
};