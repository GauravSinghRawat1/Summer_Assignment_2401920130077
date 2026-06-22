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
    void dfs(TreeNode *node, vector<int> &ans){
        if(node==nullptr){
            ans.push_back(INT_MAX);
            return;
        }
        ans.push_back(node->val);
        dfs(node->left,ans);
        dfs(node->right,ans);
        return;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ans1;
        vector<int> ans2;
        dfs(p,ans1);
        dfs(q,ans2);
        if(ans1.size()!=ans1.size()){
            return false;
        }
        else{
            for(int i=0;i<ans1.size();i++){
                if(ans1[i]!=ans2[i]){
                    return false;
                }
            }
            return true;
        }
    }
};