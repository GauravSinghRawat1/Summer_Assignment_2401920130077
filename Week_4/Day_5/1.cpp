class Solution {
public:
    int height(TreeNode* node, int h) {
        if (node == nullptr) {
            return h - 1;
        }
        return max(height(node->left, h + 1), height(node->right, h + 1));
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        int treeHeight = height(root, 0);
        for (int i = 0; i <= treeHeight; i++) {
            int levelsize = q.size();
            vector<int> currentlevel;
            currentlevel.reserve(levelsize);
            for (int j = 0; j < levelsize; j++) {
                TreeNode* currentnode = q.front();
                q.pop();
                currentlevel.push_back(currentnode->val);
                if (currentnode->left != nullptr) {
                    q.push(currentnode->left);
                } else {
                    q.push(new TreeNode(-101));
                }
                if (currentnode->right != nullptr) {
                    q.push(currentnode->right);
                } else {
                    q.push(new TreeNode(-101));
                }
            }
            int start = 0;
            int end = levelsize - 1;
            while (start <= end) {
                if (currentlevel[start] != currentlevel[end]) {
                    return false;
                }
                start++;
                end--;
            }
        }
        return true;
    }
};