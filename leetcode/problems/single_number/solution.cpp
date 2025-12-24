class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int temp = 0;
       for(int num:nums){
        temp ^= num;
       }
       return temp;
    }
};