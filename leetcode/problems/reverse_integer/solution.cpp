class Solution {
public:
    int reverse(int x) {
        int rem = 0;
        int i = 0;
        int temp = 0;

        while (x != 0) {
            rem = x % 10;
            if ((temp > INT_MAX / 10) || (temp < INT_MIN / 10)) {
                return 0;
            }
            temp = (temp * 10) + rem;
            x /= 10;
        }
        return temp;
    }
};