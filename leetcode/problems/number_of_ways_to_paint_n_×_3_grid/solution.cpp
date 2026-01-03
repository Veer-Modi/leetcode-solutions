class Solution {
public:
    int numOfWays(int n) {
        long long two = 6;
        long long three = 6;
        const int mod = 1000000007;
        for (int i = 2; i <= n; i++) {
            long long nexttwo = ((2 * three) + (3 * two)) % mod;
            long long nextthree = ((2 * three) + (2 * two)) % mod;
            two = nexttwo;
            three = nextthree;
        }
        return (two + three) % mod;
    }
};