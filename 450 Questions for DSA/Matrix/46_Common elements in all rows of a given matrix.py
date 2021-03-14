from collections import Counter

def printCommonElements(mat):
    length = len(mat)
    d = dict()
    for i in range(length+1):
        d[mat[0][i]] = d.get(mat[0][i],1)
    for i in range(1,length):
        for j in range(length+1):
            if mat[i][j] in d and d[mat[i][j]] == i:
                d[mat[i][j]]+=1
                if i == length-1:
                    print(mat[i][j], end = " ")
    # d = Counter(mat[0])
    # for i in range(1,len(mat)):
    #     for j in range(0,len(mat)):
            



mat = [[1, 2, 1, 4, 8], 
       [2, 2, 8, 2, 1], 
       [8, 7, 7, 3, 1], 
       [8, 1, 2, 7, 9]] 
  
printCommonElements(mat) 