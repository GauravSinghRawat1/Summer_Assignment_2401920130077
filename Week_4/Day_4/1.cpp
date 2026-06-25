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
    int rec(TreeNode *root, int targetSum, int &currSum){
        if(root == NULL){
            return 0;
        }
        else if(root->left == NULL && root->right == NULL){
            if(currSum+root->val == targetSum){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            currSum+=root->val;
            int left = rec(root->left,targetSum,currSum);
            int right = rec(root->right,targetSum,currSum);
            currSum-=root->val;
            return left | right;
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        int currSum = 0;
        int ans = rec(root,targetSum,currSum);
        return ans;
    }
};