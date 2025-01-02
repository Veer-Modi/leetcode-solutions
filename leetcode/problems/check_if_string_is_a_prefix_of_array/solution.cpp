class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string s2 = "";
        for (int i = 0; i < words.size(); i++) {
            s2 += words[i];
            if (s2 == s) {
                return true;
            }
        }
        return false;
    }
};