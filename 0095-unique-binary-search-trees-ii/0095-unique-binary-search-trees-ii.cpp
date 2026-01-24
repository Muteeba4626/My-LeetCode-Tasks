class Solution {
public:
    // 3D vector to store results for range [start][end]
    vector<TreeNode*> memo[10][10];

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        if (start > end) return {nullptr};
        
        // Return cached result if available
        if (!memo[start][end].empty()) return memo[start][end];

        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            // Generate all possible left and right subtrees
            vector<TreeNode*> leftSub = build(start, i - 1);
            vector<TreeNode*> rightSub = build(i + 1, end);

            for (auto l : leftSub) {
                for (auto r : rightSub) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return memo[start][end] = res;
    }
};