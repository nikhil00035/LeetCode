class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, col, row] = q.front();
            q.pop();

            nodes[col][row].insert(node->val);

            if (node->left) q.push({node->left, col - 1, row + 1});
            if (node->right) q.push({node->right, col + 1, row + 1});
        }

        vector<vector<int>> result;
        for (auto& [col, rows] : nodes) {
            vector<int> col_vals;
            for (auto& [row, vals] : rows) {
                col_vals.insert(col_vals.end(), vals.begin(), vals.end());
            }
            result.push_back(col_vals);
        }

        return result;
    }
};