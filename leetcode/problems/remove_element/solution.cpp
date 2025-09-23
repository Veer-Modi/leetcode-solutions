class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int i;
        int numsSize= nums.size();

        for (i = 0; i < numsSize; i++) {
            if (nums[i] == val) {
                count++;
            } else {
                nums[i - count] = nums[i];
            }
        }
        return numsSize - count;
    }
};