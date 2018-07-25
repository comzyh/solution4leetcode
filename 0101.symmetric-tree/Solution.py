# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def check(left, right):
            if left is None and right is None:
                return True
            if left is None or right is None:
                return False
            if left.val != right.val:
                return False
            if not check(left.left, right.right) or not check(left.right, right.left):
                return False
            return True
        return root is None or check(root.left, root.right)
