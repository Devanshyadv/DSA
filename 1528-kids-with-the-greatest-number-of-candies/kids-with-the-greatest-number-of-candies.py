class Solution:
    def kidsWithCandies(self, candies: list[int], extraCandies: int) -> list[bool]:
        maxi=float('-inf')
        result=[]
        for i in candies:
            if i>maxi:
                maxi=i
        
        for i in candies:
            if i+extraCandies<maxi:
                result.append(bool(0))
            else:
                result.append(bool(1))

        return result

        