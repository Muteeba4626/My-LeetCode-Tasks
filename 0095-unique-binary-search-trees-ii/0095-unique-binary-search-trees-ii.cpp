class Solution {
    // Memoization table to store results for a given range [start, end]
    map<pair<int, int>, vector<TreeNode*>> memo;

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

    vector<TreeNode*> buildTrees(int start, int end) {
        // Base case: if start > end, we've reached a null child
        if (start > end) return {nullptr};
        
        // Check if we've already calculated this range
        if (memo.count({start, end})) return memo[{start, end}];

        vector<TreeNode*> allTrees;

        // Iterate through each number to act as the root
        for (int i = start; i <= end; i++) {
            // Recursively generate all possible left and right subtrees
            vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
            vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);

            // Combine every left subtree with every right subtree for root 'i'
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }
        return memo[{start, end}] = allTrees;
    }
};