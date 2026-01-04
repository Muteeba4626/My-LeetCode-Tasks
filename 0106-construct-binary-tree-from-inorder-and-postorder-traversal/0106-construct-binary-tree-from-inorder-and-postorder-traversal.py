# LeetCode 106 - Construct Binary Tree from Inorder and Postorder Traversal
# https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
# Author: muteeba4266

class Solution(object):
    def buildTree(self, inorder, postorder):
        # Create a map for O(1) lookups of inorder indices
        inorder_map = {val: i for i, val in enumerate(inorder)}
        
        def construct(left, right):
            if left > right:
                return None
            
            # The last element in postorder is the root
            root_val = postorder.pop()
            root = TreeNode(root_val)
            
            # Find index in inorder to split into left and right subtrees
            index = inorder_map[root_val]
            
            # Important: Build the RIGHT subtree first because we are popping 
            # from the end of the postorder list (Left, Right, Root order)
            root.right = construct(index + 1, right)
            root.left = construct(left, index - 1)
            
            return root
            
        return construct(0, len(inorder) - 1)