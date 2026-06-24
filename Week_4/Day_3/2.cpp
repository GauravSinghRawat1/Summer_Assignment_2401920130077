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
    bool ans = true;

public:
    TreeNode* helper(TreeNode* node, long long min_val, long long max_val) {
        if (node == nullptr || !ans) {
            return nullptr;
        }
        if (node->val >= max_val || node->val <= min_val) {
            ans = false;
            return nullptr; 
        }
        
        TreeNode* left = helper(node->left, min_val, node->val);
        TreeNode* right = helper(node->right, node->val, max_val);
        
        return node;
    }

    bool isValidBST(TreeNode* root) {
        long long min_val = LONG_MIN;
        long long max_val = LONG_MAX;
        helper(root, min_val, max_val);
        return ans;
    }
};