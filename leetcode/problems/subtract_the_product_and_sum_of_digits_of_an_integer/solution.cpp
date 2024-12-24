class Solution {
public:
    int subtractProductAndSum(int n) {
        int s=0,p=1;
        while(n!=0){
            int digit = n%10;
            p*=digit;
            s+=digit;
            n/=10;
        }
        int ans = p-s;
        return ans;
    }
};