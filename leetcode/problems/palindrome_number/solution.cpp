class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int len = str.length();
        string rstr;
        rstr.resize(len);
        for (int i = 0; i < len; i++) {
            rstr[i] = str[len - 1 - i];
        }
        if(str==rstr){
            return true;
        }else{
            return false;
        }
    }
};