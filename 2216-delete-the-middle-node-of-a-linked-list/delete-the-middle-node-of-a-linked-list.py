# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: ListNode | None) -> ListNode | None:
        if head is None or head.next is None:
            return None
        fast=head
        slow=head
        temp=None
        while fast and fast.next is not None:
            fast=fast.next.next
            temp=slow
            slow=slow.next
        
        temp.next=slow.next
        
        return head
        
        


        