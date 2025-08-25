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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return symmetric(root->left, root->right);
    }
    bool symmetric(TreeNode* Node1, TreeNode* Node2) {
        if (Node1 == NULL && Node2 == NULL)
            return true;
        if (Node1 == NULL || Node2 == NULL)
            return false;
        if (Node1->val != Node2->val)
            return false;
        return symmetric(Node1->left, Node2->right) &&
               symmetric(Node1->right, Node2->left);
    }
};