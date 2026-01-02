class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string result = "";
        while (n > 0) {
            n--;
            char ch = 'A' + (n % 26);
            result += ch;
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};