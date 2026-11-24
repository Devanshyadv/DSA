class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        n=len(nums)
        sum=0
        maxi=float('-inf')
        for i in range(k):
            sum+=nums[i]
        maxi=sum/k
        i=0
        j=k
        while i<n and j<n:
            sum-=nums[i]
            sum+=nums[j]
            maxi=max(maxi,sum/k)
            i+=1
            j+=1
        return maxi


        