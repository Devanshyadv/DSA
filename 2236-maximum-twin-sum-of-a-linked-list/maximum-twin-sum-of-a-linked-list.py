# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: ListNode | None) -> int:
        fast=head
        slow=head
        while fast and fast.next:
            fast=fast.next.next
            slow=slow.next
        curr=slow
        prev=None
        while curr:
            ford=curr.next
            curr.next=prev
            prev=curr
            curr=ford

        temp1=head
        temp2=prev
        maxi=0
        while temp1 and temp2:
            sum=temp1.val + temp2.val
            maxi=max(maxi,sum)
            temp1=temp1.next
            temp2=temp2.next
        return maxi

        