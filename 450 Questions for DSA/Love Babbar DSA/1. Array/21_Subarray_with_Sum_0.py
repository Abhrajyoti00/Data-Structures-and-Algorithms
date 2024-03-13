class Solution:
    #User function Template for python3
    
    #Complete this function
    def subArrayExists(self,arr,n):
        dic_of_sums = {}
        s = arr[0]
        i = 0
        j = 1
        
        while(j<n):
            dic_of_sums[s] = dic_of_sums.get(s,0)+1
            s+=arr[j]
            if s == 0:
                return True
            if dic_of_sums.get(s) is not None:
                return True
            j+=1
        return False
sol = Solution()
arr = list(map(int, input().split()))
print(sol.subArrayExists(arr,len(arr)))
            



