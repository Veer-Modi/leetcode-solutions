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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        if (root == NULL)
            return arr;
        vector<int> left = inorderTraversal(root->left);
        arr.insert(arr.end(), left.begin(), left.end());
        arr.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        arr.insert(arr.end(), right.begin(), right.end());
        return arr;
    }
};