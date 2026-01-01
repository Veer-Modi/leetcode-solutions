class Solution {
public:
    int firstUniqChar(string s) {
        if (s == "") {
            return -1;
        }
        map<char, int> m;
        for (char ch : s) {
            m[ch]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};