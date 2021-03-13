def kthSmallest(arr, l, r, k):
    '''
    arr : given array
    l : starting index of the array i.e 0
    r : ending index of the array i.e size-1
    k : find kth smallest element and return using this function
    '''
    arr.sort()
    return(arr[k-1])



for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    k = int(input())
    print(kthSmallest(a, 0, n-1, k))


## Better Method = use min or max heap, pop k elements, return temporary  O(n + kLogn)
## Best Method = Use median of median algorithm  o(n) in worst case
