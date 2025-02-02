class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool repeated = false;
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        repeated = true;
                        break;
                    }
                }
                if (repeated) {
                    break;
                }
                maxLength = max(maxLength, j - i + 1);
            }
        }
        return maxLength;
    }
};