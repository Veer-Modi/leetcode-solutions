class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() <= 0) {
            return 0;
        }
        int len = 0;
        int lastlen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!isspace(s[i])) {
                len++;
                lastlen = len;
            } else {
                len = 0;
            }
        }
        return lastlen;
    }
};