class Solution {
public:
    bool isPowerOfTwo(int n) {
        int base=2;
    
    for(int i=0;i<31;i++){
        if(pow(base,i)==n){
            return true;
            break;
        }
    }
    return false;
    }
};