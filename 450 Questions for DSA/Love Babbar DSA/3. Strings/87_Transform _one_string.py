def minOps(A,B):
    n = len(B)
    count = [0] * 256

    for i in range(n):        # count characters in A
        count[ord(B[i])] += 1
    for i in range(n):        # subtract count for every char in B
        count[ord(A[i])] -= 1
    for i in range(256):    # Check if all counts become 0
        if count[i]:
            return -1

    # A = "A D C B"
                
    # B = "A B C D"


    i = n-1
    j = n-1

    res = 0
    while i>=0:
        while i>=0  and A[i]!=B[j]:
            i-=1
            res+=1
        if i>=0: # Means A[i] = B[j]
            i-=1
            j-=1
    return res




A = input()
B = input()

print(minOps(A,B))
