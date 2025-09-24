class Solution {
public:
    bool isPerfectSquare(int num) {
        int sqn = sqrt(num);
        if (sqn * sqn == num) {
            return true;
        }
        return false;
    }
};