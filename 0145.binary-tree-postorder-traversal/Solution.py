# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []

        def travel(root):
            if root is None:
                return
            travel(root.left)
            travel(root.right)
            result.append(root.val)
        travel(root)
        return result
