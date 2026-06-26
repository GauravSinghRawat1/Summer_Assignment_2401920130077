/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfsencoding(TreeNode *root, string &s){
        if(root == NULL){
            s += "#,";
        }
        else{  
            s += to_string(root->val)+","; 
            dfsencoding(root->left,s);
            dfsencoding(root->right,s);
        }
    }
    string serialize(TreeNode* root) {
        int p1 = 0;
        string encode = "";
        dfsencoding(root,encode);
        return encode;
    }
    TreeNode* dfsdecoding(int &p1, string &s){
        string curr = "";
        while(p1<s.size() && s[p1]!=','){
            curr+=s[p1];
            p1+=1;
        }
        p1+=1;
        if(curr == "#"){
            return NULL;
        }
        else{
            cout << curr << "\n";
            TreeNode *root = new TreeNode(stoi(curr));
            root->left = dfsdecoding(p1,s);
            root->right = dfsdecoding(p1,s);
            return root;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p1 = 0;
        TreeNode *root = dfsdecoding(p1,data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));