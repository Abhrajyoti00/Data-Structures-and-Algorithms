arr = list(map(int,input().split(',')))
neg = 0
pos = len(arr)-1

while(neg<=pos):
    if arr[neg]<0 and arr[pos]<=0:
        neg+=1
    elif arr[neg]>=0 and arr[pos]<0:
        arr[neg], arr[pos] = arr[pos], arr[neg]
        neg+=1
        pos-=1
    elif arr[neg]<0 and arr[pos]>=0:
        neg+=1
        pos-=1

print(arr)
