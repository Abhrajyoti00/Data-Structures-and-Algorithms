from bisect import bisect_right
class Solution:
    def median(self, matrix, r, c):
        
        mi = matrix[0][0]
        mx = 0
        desired = ((r*c)+1)//2
        #Finding the min and max of the matrix
        for i in range(r):
            if mi>matrix[i][0]:
                mi = matrix[i][0]
            if mx<matrix[i][-1]:
                mx = matrix[i][-1]
        
        while(mi<mx):
            mid = mi+ (mx-mi)//2
            count = [0]
            
            for i in range(r):
                ind = bisect_right(matrix[i], mid)  
                '''#Bisect right gives the next index 
                If the element is already present in the list, the right most position where element has to be inserted is returned.
                '''
                count[0]+= ind
            
            if count[0]<desired:
                mi = mid+1

            else:
                mx = mid
        return mi
        

      
# Driver code 
r, c = 3,3
sol = Solution()
m = [[1, 3, 5], [2, 6, 9], [3, 6, 9]] 
print(sol.median(m, r, c)) 
