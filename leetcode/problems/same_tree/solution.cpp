/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> s1, s2;
        s1.push(p);
        s2.push(q);

        while (!s1.empty() && !s2.empty()) {
            TreeNode* temp1 = s1.front();
            s1.pop();
            TreeNode* temp2 = s2.front();
            s2.pop();

            if (!temp1 && !temp2)
                continue;

            if (!temp1 || !temp2)
                return false;

            if (temp1->val != temp2->val)
                return false;

            s1.push(temp1->left);
            s2.push(temp2->left);
            s1.push(temp1->right);
            s2.push(temp2->right);
        }

        return s1.empty() && s2.empty();
    }
};