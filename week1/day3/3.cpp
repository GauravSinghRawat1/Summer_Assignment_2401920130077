/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs_check(TreeNode *node, TreeNode *subRoot){
        if(node == NULL && subRoot !=NULL || node != NULL && subRoot == NULL){
            return false;
        }
        else if(node == NULL && subRoot ==NULL){
            return true;
        }
        else if(node->val != subRoot->val){
            return false;
        }
        else{
            bool left = dfs_check(node->left,subRoot->left);
            bool right = dfs_check(node->right,subRoot->right);
            return left & right;
        }
    }
    void dfs(TreeNode* node, TreeNode* subRoot, bool &ans){
        if(node == NULL){
            return;
        }
        else{
            if(node->val == subRoot-> val){
                ans = ans | dfs_check(node,subRoot);
            }
            dfs(node->left,subRoot,ans);
            dfs(node->right,subRoot,ans);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        dfs(root,subRoot,ans);
        return ans;
    }
};