class Solution {
public:
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return constructTree(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* constructTree(vector<int>& preorder, int left, int right) {
        if (left > right) return NULL;

        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int inorderIndex = inorderMap[rootValue];

        root->left = constructTree(preorder, left, inorderIndex - 1);
        root->right = constructTree(preorder, inorderIndex + 1, right);

        return root;
    }
};
