class Solution:
    def findDifference(self, nums1: list[int], nums2: list[int]) -> list[list[int]]:
        ans=list()
        a=set(nums1)
        b=set(nums2)
        c=a-b
        d=b-a
        ans.append(list(c))
        ans.append(list(d))
        return ans

        