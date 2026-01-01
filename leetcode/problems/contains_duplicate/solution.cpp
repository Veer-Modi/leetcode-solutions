class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n;
        for (int x : nums) {
            if (n.count(x))
                return true;
            n.insert(x);
        }
        return false;
    }
};