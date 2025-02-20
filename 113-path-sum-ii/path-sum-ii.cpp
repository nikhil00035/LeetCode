class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currentPath;
        dfs(root, targetSum, currentPath);
        return result;
    }

private:
    void dfs(TreeNode* node, int targetSum, vector<int>& currentPath) {
        if (!node) return;

        currentPath.push_back(node->val);
        targetSum -= node->val;

        if (!node->left && !node->right && targetSum == 0) {
            result.push_back(currentPath);
        } else {
            dfs(node->left, targetSum, currentPath);
            dfs(node->right, targetSum, currentPath);
        }

        currentPath.pop_back();
    }
};