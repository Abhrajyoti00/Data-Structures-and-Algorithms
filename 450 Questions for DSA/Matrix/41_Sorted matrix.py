class Solution:
    
    def sortedMatrix(self,N,Mat):
        Big_list = []
        ans_list = []
        
        for lists in Mat:
            for ele in lists:
                Big_list.append(ele)

        Big_list.sort()
        for i in range(N):
            small_list = []
            for j in range(N):
                
                small_list.append(Big_list.pop())
            ans_list.append(small_list[::-1])
        return ans_list[::-1]
sol = Solution()
N=3
Mat=[[1,5,3],[2,8,7],[4,6,9]]
print(sol.sortedMatrix(N,Mat))
