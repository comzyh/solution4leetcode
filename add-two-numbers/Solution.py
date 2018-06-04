# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = None
        current = None
        carry = 0
        while l1 is not None or l2 is not None or carry != 0:
            val = (l1.val if l1 is not None else 0) + (l2.val if l2 is not None else 0) + carry
            carry = val // 10
            if current is None:
                result = ListNode(val % 10)
                current = result
            else:
                current.next = ListNode(val % 10)
                current = current.next
            l1 = l1.next if l1 is not None else None
            l2 = l2.next if l2 is not None else None
        return result