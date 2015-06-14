# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}

    def invertTree(self, root):
        if root is not None:
            if root.left is not None:
                self.invertTree(root.left)
            if root.right is not None:
                self.invertTree(root.right)
            root.left, root.right = root.right, root.left
        return root
