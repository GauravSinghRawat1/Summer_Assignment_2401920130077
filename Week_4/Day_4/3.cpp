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
    int dfs(TreeNode *node,int &curr,int &ans){
        if(node == NULL){
            return 0;
        }
        else{
            int val1 = dfs(node->left,curr,ans);
            int val2 = dfs(node->right,curr,ans);
            curr = node->val+max(0,max(val1,val2));
            ans = max(ans,max(curr,node->val+val1+val2));
            return curr;
        }
    }
    int maxPathSum(TreeNode* root) {
        int curr = 0;
        int ans = INT_MIN;
        curr = dfs(root,curr,ans);
        return ans;
    }
};