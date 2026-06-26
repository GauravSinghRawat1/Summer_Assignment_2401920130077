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
    TreeNode* CreateTree(vector<int> tree,vector<int>& preorder,unordered_map<int,int> &m){
        if(tree.size()==1){
            return new TreeNode(tree[0]);
        }
        int miniIndex = INT_MAX;
        int index;
        for(int i=0;i<tree.size();i++){
            if(m[tree[i]]<miniIndex){
                miniIndex = m[tree[i]];
                index = i;
            }
        }
        vector<int> newleft(tree.begin(),tree.begin()+index);
        vector<int> newright(tree.begin()+index+1,tree.end());
        TreeNode* leftsubtree = NULL;
        TreeNode* rightsubtree = NULL;
        if(newleft.size()!=0){
            leftsubtree = CreateTree(newleft,preorder,m);
        }
        if(newright.size()!=0){
            rightsubtree = CreateTree(newright,preorder,m);
        }
        TreeNode* head = new TreeNode(tree[index]);
        head->left = leftsubtree;
        head->right = rightsubtree;
        return head;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==1){
            return new TreeNode(inorder[0]);
        }
        else{
            unordered_map<int,int> m;
            for(int i=0;i<preorder.size();i++){
                m[preorder[i]] = i;
            }
            TreeNode* ans = CreateTree(inorder,preorder,m);
            return ans;
        }
    }
};