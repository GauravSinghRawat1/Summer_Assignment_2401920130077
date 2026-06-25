/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int diameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        height(root);
        return diameter;
    }

    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftheight = height(node->left);
        int rightheight = height(node->right);

        int dia = leftheight + rightheight;
        diameter = std::max(dia, diameter);

        return std::max(leftheight, rightheight) + 1;
    }
};