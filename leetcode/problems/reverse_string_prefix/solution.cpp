class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();
        if (n == k) {
            reverse(s.begin(), s.end());
            return s;
        } else if (k == 1) {
            return s;
        } else {
            int l = 0, r = k - 1;
            while (l <= r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};