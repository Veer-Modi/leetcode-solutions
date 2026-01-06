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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        long long maxSum = LLONG_MIN;
        int answerLevel = 1;
        while (!q.empty()) {
            int levelSize = q.size();
            int currentSum = 0;
            for (int i = 1; i <= levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentSum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
                answerLevel = level;
            }
            level++;
        }
        return answerLevel;
    }
};