def getMinDiff(arr, n, k):
    arr = list(set(arr))
    arr = sorted(arr)
    
    n = len(arr)
    mxs=list()
    mns=list()
    for i in arr:
        mxs.append(i+k)
        mns.append(i-k)
    ans=arr[-1]-arr[0]
    for i in range(1,n):
        if(mns[i]>=0):
            ''' 
            Trick, we need to get the minimum difference between the largest and the smallest
            heights Now a difference is minimum if the first no is as small as possible,
            and the second no is as large as possible, but first no > second no [So that
            the difference is positive].
            So we have 2 parts : 1) For largest we choose the minimum no.s. So in the last no.
            in mns[n-1] and mxs[i-1] are the smallest largests possible. And the mns[i] and
            mxs[0] is the largest smallest possible. 
            '''
            ans=min(ans,max(mns[n-1],mxs[i-1])-min(mns[i],mxs[0]))
    return ans 

a=[6, 1, 9, 1, 1, 7, 9, 5, 2, 10]
print(getMinDiff(a,len(a),4))