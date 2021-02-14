# // O(n*m) Time, O(1) Space

def merge(arr1, arr2, n, m):
    for i in range(n):
        if arr1[i]>=arr2[0]:
            arr1[i], arr2[0] = arr2[0], arr1[i]
            arr2.sort()
    # arr1.sort()
    # print(arr1)
    # print(arr2)


arr1 = list(map(int,input().split()))
n = len(arr1)
arr2 = list(map(int,input().split()))
m = len(arr2)
merge(arr1,arr2,n,m)
print(arr1)
print(arr2)

