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
    void bfs(TreeNode* root,vector<vector<int>> &ans){
        if(root == NULL){
            return; 
        }
        ans.push_back({root->val});
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while(!q.empty()){
            vector<int> temp;
            for(int i=0;i<cnt;i++){
                TreeNode* node = q.front();
                if(node->left!=NULL){
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
                q.pop();
            }  
            cnt = temp.size();
            if(temp.size()!=0){
                ans.push_back(temp);   
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(root,ans);
        return ans;
    }
};