class Solution {
public:
    bool isPerfectSquare(int num) {
        int sqrtn = sqrt(num);
        if (sqrtn * sqrtn == num) {
            return true;
        } else {
            return false;
        }
    }
};