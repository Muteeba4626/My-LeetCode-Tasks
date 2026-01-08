# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# LeetCode 24 - Swap Nodes in Pairs
# https://leetcode.com/problems/swap-nodes-in-pairs/
# Author: muteeba4266

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Base case: if list is empty or has only one node
        if not head or not head.next:
            return head
            
        # Nodes to be swapped
        first = head
        second = head.next
        
        # Swapping logic using recursion
        first.next = self.swapPairs(second.next)
        second.next = first
        
        # The second node is now the head of the swapped pair
        return second