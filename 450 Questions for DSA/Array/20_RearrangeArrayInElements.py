def Rearrange(arr):
    i = 0
    j = len(arr)-1
    while(i<j):
        if arr[i]>=0 and arr[j]<0:
            i+=1
            j-=1
        elif arr[i]>=0 and arr[j]>0:
            i+=1
        elif arr[i]<0 and arr[j]<0:
            j-=1
        elif arr[i]<0 and arr[j]>=0:
            arr[i], arr[j] = arr[j], arr[i]
    
    #Now i is pointing to the start of neg array, 2 3 4 -1 -5 -6
    i+=1
    k = 0
    start_of_neg = i
    print(arr)
    while(i<len(arr)):
        arr[k], arr[i] = arr[i], arr[k]
        i+=1
        k+=2
        
    print(arr)
    return


    

# arr = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
# arr = [1,2,-1,6,-4,-3,8,7]
arr = [-1, 2, -3, 4, 5, 6, -7, 8, -9]
# arr = [-1,2,-3,4,5,8,9,-10,11,-12]
Rearrange(arr)