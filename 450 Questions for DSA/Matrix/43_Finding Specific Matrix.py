# An efficient method to find maximum value  
# of mat[d] - ma[a][b] such that c > a and d > b 
  
import sys 
N = 5
  
# The function returns maximum value  
# A(c,d) - A(a,b) over all choices of  
# indexes such that both c > a and d > b. 
def findMaxValue(mat):
    maxValue = -sys.maxsize-1
    maxArr = [[0 for i in range(N)] for j in range(N)]
    maxv = mat[N-1][N-1]
    #Initializing Last Row
    
    maxArr[N-1][N-1] = mat[N-1][N-1]
    for j in range(N-2,-1,-1):
        if mat[N-1][j] > maxv:
            maxv = mat[N-1][j]
        maxArr[N-1][j] = maxv

    maxv = mat[N-1][N-1]
    for i in range(N-2,-1,-1):
        if mat[i][N-1] > maxv:
            maxv = mat[i][N-1]
        maxArr[i][N-1] = maxv
    
    #preproc




    print(maxArr)
    return maxValue 
  
# Driver Code 
mat = [[ 1, 2, -1, -4, -20 ], 
       [-8, -3, 4, 2, 1 ], 
       [ 3, 8, 6, 1, 3 ], 
       [ -4, -1, 1, 7, -6] , 
       [0, -4, 10, -5, 1 ]] 
                      
print ("Maximum Value is", 
        findMaxValue(mat))