class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        } else {
            int num1 = 1, num2 = 2, temp;
            for (int i = 3; i <= n; i++) {
                temp = num1 + num2;
                num1 = num2;
                num2 = temp;
            }
            return num2;
        }
    }
};