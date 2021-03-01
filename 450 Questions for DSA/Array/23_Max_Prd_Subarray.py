#User function Template for python3
class Solution:
    def maxProduct(self,arr, n):
        minValue = arr[0]
        maxValue = arr[0]
        maxPr = arr[0]
        for i in range(1,n):
            if arr[i] < 0:
                minValue, maxValue = maxValue, minValue
            minValue = min(arr[i], minValue*arr[i])
            maxValue = max(arr[i], maxValue*arr[i])
            maxPr = max(maxPr, maxValue, minValue)
        
        return maxPr


sol = Solution()

# arr = list(map(int, input().split()))
# arr = [8, -2 ,-2 ,0 ,8 ,0, -6 ,-8 ,-6,-1]
arr = [-8, 5,3,1,6]
print(sol.maxProduct(arr, len(arr)))