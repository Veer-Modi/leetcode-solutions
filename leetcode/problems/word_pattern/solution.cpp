class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        int i = 0;
        int n = s.size();
        int idx = 0;
        while (idx < n) {
            if (i >= pattern.size())
                return false;
            string word = "";
            while (idx < n && s[idx] != ' ') {
                word += s[idx];
                idx++;
            }
            char ch = pattern[i];
            if (charToWord.count(ch) && charToWord[ch] != word)
                return false;
            if (wordToChar.count(word) && wordToChar[word] != ch)
                return false;
            charToWord[ch] = word;
            wordToChar[word] = ch;
            i++;
            idx++;
        }
        return i == pattern.size();
    }
};