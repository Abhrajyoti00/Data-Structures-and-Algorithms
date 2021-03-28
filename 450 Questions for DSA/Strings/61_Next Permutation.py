 def swap(arr,i1,i2):
    arr[i1], arr[i2] = arr[i2], arr[i1]
def reverse(arr, start, end):
    while start<end:
        swap(arr, start, end)
        start+=1
        end-=1

    
def nextPermutation(arr):
    ind1 = -1
    ind2 = -1
    for i in range(len(arr)-2, -1, -1):
        if arr[i]<arr[i+1]:
            ind1 = i
            break
    if ind1 == -1: #Means the largest permutation
        arr.sort()
        # return
    else:
        for i in range(len(arr)-1, -1, -1):
            if arr[i]>arr[ind1]:
                ind2 = i
                break
        arr[ind1], arr[ind2] = arr[ind2], arr[ind1]
        reverse(arr, ind1+1, len(arr)-1)
    return arr

# arr = [1,3,5,4,2]
arr = [1,3,2]
print(nextPermutation(arr))
    
    