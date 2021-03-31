def solve(i,j,string, matrix,  total_rows, total_cols, idx):
    found = 0
    

    if i>=0 and i<total_rows and j>= 0 and j<total_cols and string[idx] == matrix[i][j]:
        temp = string[idx]

        matrix[i][j] = 0
        idx+=1
        if idx == len(string):
            found = 1
        else:
            found+= solve(i-1,j,string, matrix,  total_rows, total_cols, idx)
            found+= solve(i,j-1,string, matrix,  total_rows, total_cols, idx)
            found+= solve(i,j+1,string, matrix,  total_rows, total_cols, idx)
            found+= solve(i+1,j,string, matrix,  total_rows, total_cols, idx)
        matrix[i][j] = temp  #For Backtracking
    return found

def search(string, matrix,  total_rows, total_cols):
    idx = 0  #Current index
    ans = 0
    for i in range(total_rows):
        for j in range(total_cols):
            ans+=solve(i,j,string, matrix,  total_rows, total_cols, idx)
    return ans

string = "MAGIC"
mat = ["BBABBM","CBMBBA","IBABBG",
            "GOZBBI","ABBBBC","MCIGAM"]

matrix = [0]*len(mat)
for i in range(len(mat)):
    matrix[i] = list(mat[i])

total_rows = len(matrix)
total_cols = len(matrix[0])
print(search(string, matrix, total_rows, total_cols))