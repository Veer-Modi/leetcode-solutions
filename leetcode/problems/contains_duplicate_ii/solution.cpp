class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> val;
        for (int i = 0; i < nums.size(); i++) {
            if (val.count(nums[i]) && (i - val[nums[i]] <= k)) {
                return true;
            }
            val[nums[i]] = i;
        }
        return false;
    }
};