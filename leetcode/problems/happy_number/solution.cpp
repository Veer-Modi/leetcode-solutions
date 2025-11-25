class Solution {
public:
    int sum(int n) {
        int h = 0;
        while (n > 0) {
            int temp = n % 10;
            h += temp * temp;
            n /= 10;
        }
        return h;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = sum(slow);
            fast = sum(sum(fast));
        } while (slow != fast);
        return (slow == 1);
    }
};