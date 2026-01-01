class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> Smap;
        unordered_map<char, char> Tmap;
        for (int i = 0; i < s.size(); i++) {
            char a = s[i];
            char b = t[i];
            if (Smap.count(a) && Smap[a] != b)
                return false;
            if (Tmap.count(b) && Tmap[b] != a)
                return false;
            Smap[a] = b;
            Tmap[b] = a;
        }
        return true;
    }
};