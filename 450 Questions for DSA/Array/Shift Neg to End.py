# arr = list(map(int,input().split('')))
# arr = [1 ,-1 ,-3 , -2, 7, 5, 11, 6 ]
arr = [-5, 7, -3, -4, 9, 10, -1, 11]
positive = 0
negative = len(arr)-1

while(positive <= negative):
    if arr[positive] >= 0 and arr[negative] >= 0:
        positive += 1
    elif arr[positive] < 0 and arr[negative] >= 0:
        arr[positive], arr[negative] = arr[negative], arr[positive]
        positive += 1
        negative -= 1
    elif arr[positive] >= 0 and arr[negative] < 0:
        positive += 1
        negative -= 1

print(arr)
