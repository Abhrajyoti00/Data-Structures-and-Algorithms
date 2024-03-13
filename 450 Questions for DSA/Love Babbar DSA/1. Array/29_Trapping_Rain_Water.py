class Solution:
    # TC o(N), SC: O(N) 
    def trappingWater1(self, arr,n):
        prefixArray = []
        suffixArray = [0 for i in range(n)]
        prefixArray.append(arr[0])
        suffixArray[n-1] = arr[n-1]
        
        for i in range(1,n):

            max_element = max(prefixArray[i-1], arr[i])
            # print(max_element)
            prefixArray.append(max_element)
        for i in range(n-2,-1,-1):
            # print('i = ', i)
            # print('arr[i] = ', arr[i])
            # print('suffixArray', [n-i-2], ' = ', suffixArray[n-i-2])
            max_element = max(suffixArray[i+1], arr[i])
            # print(max_element)
            suffixArray[i] = (max_element)
        ans = 0
        # print(prefixArray)
        # print(suffixArray)

        for i in range(n):
            # print('prefixArray[i] = ', prefixArray[i])
            # print('SuffixArray[i] = ', suffixArray[i])
            ans+= min(prefixArray[i], suffixArray[i])-arr[i]
        
        return ans

    # o(N) TC, O(1) SC --- Most Optimal

    def trappingWater2(self, arr,n):
        high = n-1
        low = 0
        left_max = 0
        right_max = 0
        ans = 0

        while(low<high):
            if arr[low]<arr[high]:  #Means left one is the minimum
                if arr[low] > left_max: #Means the current value is the largest from left, so we need to update it
                    left_max = arr[low]
                else:
                    ans+=left_max-arr[low]
                low+=1
            else:
                if arr[high] > right_max:
                    right_max = arr[high]
                else:
                    ans+=right_max-arr[high]
                high-=1
        return ans





sol = Solution()
# arr = [3,0,0,2,0,4]
# arr = [8 ,8 ,2 ,4 ,5 ,5,1]
# arr = [1 ,1 ,5, 2, 7, 6, 1 ,4 ,2 ,3]
#n = 7
#prefixArray = [3,3,3,3,3,4]
#suffixArray = [4,4,4,4,4,4]
print(sol.trappingWater2(arr,len(arr)))