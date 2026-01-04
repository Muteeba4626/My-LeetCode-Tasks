# LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal
# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
# Author: muteeba4266

class Solution(object):
    def buildTree(self, preorder, inorder):
        # Create a map for O(1) lookups of inorder indices
        inorder_map = {val: i for i, val in enumerate(inorder)}
        
        # Use an iterator for preorder to always fetch the current root in O(1)
        pre_iter = iter(preorder)
        
        def construct(left, right):
            if left > right:
                return None
            
            # Get the next root value from preorder traversal
            root_val = next(pre_iter)
            root = TreeNode(root_val)
            
            # Find the split point in inorder traversal
            index = inorder_map[root_val]
            
            # Recursively build left and right subtrees
            root.left = construct(left, index - 1)
            root.right = construct(index + 1, right)
            
            return root
            
        return construct(0, len(inorder) - 1)