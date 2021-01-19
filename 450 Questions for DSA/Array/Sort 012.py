

#User function Template for python3

def sort012(arr,n):
    cnt0 = 0
    cnt1 = 0
    cnt2 = 0

    for i in arr:
        if i == 0:
            cnt0+=1
        if i == 1:
            cnt1+=1
        if i == 2:
            cnt2+=1
    # arr = []
    i=0
    while (cnt0 > 0): 
        arr[i] = 0
        i+=1
        cnt0-=1
      
    # Then all the 1s 
    while (cnt1 > 0): 
        arr[i] = 1
        i+=1
        cnt1-=1
      
    # Finally all the 2s 
    while (cnt2 > 0): 
        arr[i] = 2
        i+=1
        cnt2-=1

    
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    sort012(arr,n)
    for i in arr:
        print(i, end = ' ')
    print()