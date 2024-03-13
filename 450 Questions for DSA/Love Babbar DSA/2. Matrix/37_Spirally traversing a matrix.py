class Solution:
    #User function Template for python3
    
    def spirallyTraverse(self,matrix, r, c):
        top = 0
        down = r-1
        left = 0
        right = c-1
        dirn = 0 #Direction Pointer. 0 - L to R, 1 - T to D, 2 - R to L, 3 - Down to Up
        spiral_list = []
        while (top<=down and left<=right):
            if dirn == 0: #Left to Right
                for i in range(left, right+1):
                    spiral_list.append(matrix[top][i])
                top+=1  #Move the top pointer down
            
            elif dirn == 1: #Top to Down
                for i in range(top, down+1):
                    spiral_list.append(matrix[i][right])  #Since we are now in right
                right-=1  #Move the right pointer one side left
            
            elif dirn == 2: #Right to Left
                for i in range(right, left-1, -1):
                    spiral_list.append(matrix[down][i])  #Since we are now in down
                down-=1  #Move the down pointer one side up
           
            elif dirn == 3: #Down to Up
                for i in range(down, top-1, -1):
                    spiral_list.append(matrix[i][left])  #Since we are now in left
                left+=1  #Move the left pointer one side right
            
            dirn = (dirn+1)%4  #To continue moving
        return spiral_list

sol = Solution()
rc = list(map(int, input().split()))
r = rc[0]
c = rc[1]
n=1

matrix = []
for i in range(r):
    row_list = []
    for j in range(c):
        row_list.append(n)
        n+=1
    matrix.append(row_list)
print('Spiral Matrix:- ')
print('Original Matrix :', matrix)
print(sol.spirallyTraverse(matrix, r, c))