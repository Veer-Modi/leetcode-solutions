class Solution {
public:
    int subtractProductAndSum(int n) {
        int s = 0, p = 1;
        while (n != 0) {
            int digit = n % 10;
            s += digit;
            p *= digit;
            n = n / 10;
        }
        int result = p - s;
        return result;
    }
};