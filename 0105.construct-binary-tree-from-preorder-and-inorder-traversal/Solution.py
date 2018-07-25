# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return None
        pivot = inorder.index(preorder[0])
        ret = TreeNode(preorder[0])
        ret.left = self.buildTree(preorder[1:1 + pivot], inorder[:pivot])
        ret.right = self.buildTree(preorder[1 + pivot:], inorder[pivot + 1:])
        return ret
