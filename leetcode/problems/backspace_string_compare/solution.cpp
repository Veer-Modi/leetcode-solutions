class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (i > 0) {
                    s.erase(i - 1, 2);
                    i -= 2;
                } else {
                    s.erase(i, 1);
                    i -= 1;
                }
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#') {
                if (i > 0) {
                    t.erase(i - 1, 2);
                    i -= 2;
                } else {
                    t.erase(i, 1);
                    i -= 1;
                }
            }
        }
        return s == t ? true : false;
    }
};