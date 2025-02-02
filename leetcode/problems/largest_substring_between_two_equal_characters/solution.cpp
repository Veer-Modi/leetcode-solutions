class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
         int maxLength = -1;
    
    for (int i = 0; i < s.length(); i++) {
        for (int j = s.length() - 1; j > i; j--) {
            if (s[i] == s[j]) {  
                int length = j - i - 1;
                maxLength = max(maxLength, length);
                break;
            }
        }
    }
    
    return maxLength;
    }
};