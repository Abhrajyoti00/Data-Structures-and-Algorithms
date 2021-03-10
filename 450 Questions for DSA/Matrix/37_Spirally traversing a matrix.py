class Solution:
    #User function Template for python3
    
    def spirallyTraverse(self,matrix, r, c):
        top = 0
        down = r-1
        left = 0
        right = c-1
        dirn = 0 #Direction Pointer. 0 - L to R, 1 - T to D, 2 - R to L, 3 - Down to Up
        
