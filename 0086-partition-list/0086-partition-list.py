# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        # 1. Initialize dummy nodes to represent the start of our two lists
        less_head = ListNode(0)
        greater_head = ListNode(0)
        
        # 2. Pointers to the current 'tail' of our two lists
        less = less_head
        greater = greater_head
        
        # 3. Traverse the original list
        current = head
        while current:
            if current.val < x:
                less.next = current
                less = less.next
            else:
                greater.next = current
                greater = greater.next
            current = current.next
            
        # 4. Crucial step: Terminate the greater list to avoid cycles
        # If the last node in 'greater' still points to a 'less' node, you get a loop!
        greater.next = None
        
        # 5. Connect the two lists: tail of 'less' -> head of 'greater'
        less.next = greater_head.next
        
        return less_head.next