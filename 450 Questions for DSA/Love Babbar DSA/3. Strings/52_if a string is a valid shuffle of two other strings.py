def shuffleCheck(s1,s2,s3):
    i = 0
    j = 0
    k = 0
    while(k<len(s3)):
        if(i<len(s1) and s1[i] == s3[k]):
            i+=1
        elif(j<len(s2) and s2[j] == s3[k]):
            j+=1
        else:
            return False
        k+=1
    if(i<len(s1) or j<len(s2)):
        return False
    return True

A = "AB"
B = "CD"
# C = "ACBG"
C = "BCAD"
if shuffleCheck(A, B, C): 
    print (C + " is interleaved of " + A + " and " + B )
else: 
    print (C + " is not interleaved of " + A + " and " + B )
       