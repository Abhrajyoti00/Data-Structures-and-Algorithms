class Solution:
    #User function Template for python3
    
    # arr[] : the input array
    # N : size of the array arr[]
    
    # return the length of the longest subsequene of consecutive integers
    def findLongestConseqSubseq(self,arr, N):
        d = dict()
        for ele in arr:
            d[ele] = d.get(ele, 1)
        count = 0
        ans = -1000000001
        for i in range(min(d.keys()), max(d.keys())+1):
            if(d.get(i) is None and d.get(i+1)==1):
                count = 0
            if (d.get(i) == 1):
                count+=1
            ans = max(ans, count)
        
        return ans

sol = Solution()
print(sol.findLongestConseqSubseq([1,9,3,10,4,20,2], 8))
