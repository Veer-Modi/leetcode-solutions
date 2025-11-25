class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int m = 0;
        for(int num : nums){
            if(count == 0){
                m = num;
            }
            if(num == m){
                count++;
            }else{
                count--;
            }
        }
        return m;

    }
};