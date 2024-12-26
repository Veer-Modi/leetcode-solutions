class Solution {
public:
    int bitwiseComplement(int n) {
        int x = 1;
        if (n == 0) {
            return 1;
        }
        while (x <= n) {
            n = n ^ x;
            x = x << 1;
        }
        return n;
    }
};