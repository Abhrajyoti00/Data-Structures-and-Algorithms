def isPalin(n):
    k = n
    s = 0
    while(k!=0):
        r = k%10
        s = s*10+r
        k = k//10
    return (s==n)

def PalinArray(arr ,n):
    for ele in arr:
        if isPalin(ele) is False:
            return 0

    return 1

arr = [111 ,222 ,333 ,444 ,555]
arr = [121, 131, 20]
print(PalinArray(arr, len(arr)))


