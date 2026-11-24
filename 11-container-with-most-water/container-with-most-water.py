class Solution:
    def maxArea(self, height: list[int]) -> int:
        l=0
        r=len(height)-1
        maxi=float('-inf')
        while l<r:
            maxi=max(maxi,(min(height[l],height[r])*(r-l)))
            if height[l]<height[r]:
                l+=1
            else:
                r-=1
        return maxi

        