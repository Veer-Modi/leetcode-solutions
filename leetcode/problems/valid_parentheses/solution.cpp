class Solution {
public:
    bool isValid(string s) {
        stack<char> val;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                val.push(ch);
            } else {
                if (val.empty())
                    return false;

                char top = val.top();
                val.pop();
                if ((ch == ')' && top != '(') || (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                    return false;
            }
        }
        return val.empty();
    }
};