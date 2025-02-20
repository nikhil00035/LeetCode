class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);

            if (!stk.empty()) node->right = stk.top();
            node->left = nullptr;
        }
    }
};