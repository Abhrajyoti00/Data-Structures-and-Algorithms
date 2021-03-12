class Solution:
    def rowWithMax1s(self,arr, n, m):
        count = 0
        already_reached = m
        max_row = -1
        i = 0
        while(i<n and (already_reached-1) >=0):
            for j in range(already_reached-1, -1, -1):
                if arr[i][j] == 1:
                    max_row = i
                    count+=1
                    already_reached = j
                if arr[i][j] == 0:
                    i+=1
                    break
        return max_row
sol = Solution()
arr = [[0, 1, 1, 1],
           [0, 0, 1, 1],
           [1, 1, 1, 1],
           [0, 0, 0, 0]]
arr = [[0, 0], [1, 1]]
n = 2
m = 2
print(sol.rowWithMax1s(arr,n,m))