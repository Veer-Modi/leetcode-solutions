class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (size_t i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], static_cast<int>(i)};
            }

            numMap[nums[i]] = static_cast<int>(i);
        }

        return {};
    }
};