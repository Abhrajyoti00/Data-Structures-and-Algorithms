n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))
# maxpist = 0 #Max profit if sold today
# leastsf = 0  #Least so far
# dpl = [0 for i in range(n+1)] #Dp of max if sold upto today
# for i in range(1,n):
#     if arr[i]<leastsf:
#         leastsf = arr[i]
#     maxpist = arr[i] - leastsf
#     if maxpist > dpl[i-1]:
#         dpl[i] = maxpist
#     else:
#         dpl[i] = dpl[i-1]

# maxpibt = 0 #Max profit if  bought today
# maxat = arr[len(arr)-1]
# dpr = [0 for i in range(n+1)] #Dp of max if sold upto today

# for i in range(len(arr)-2, -1, -1):
#     if arr[i] > maxat:
#         maxat = arr[i]
#     maxpibt  = maxat-arr[i]
#     if maxpibt > dpr[i+1]:
#         dpr[i] = maxpibt
#     else:
#         dpr[i] = dpr[i+1]

# op = 0
# for i in range(n):
#     print('op = ', op)
#     op = max(op, (dpl[i]+dpr[i]))

# print(op)




def maxProfit(price, n):
 
    # Create profit array and initialize it as 0
    profit = [0]*n
 
    # Get the maximum profit
    # with only one transaction
    # allowed. After this loop,
    # profit[i] contains maximum
    # profit from price[i..n-1]
    # using at most one trans.
    max_price = price[n-1]
 
    for i in range(n-2, 0, -1):
 
        if price[i] > max_price:
            max_price = price[i]
 
        # we can get profit[i] by
        # taking maximum of:
        # a) previous maximum,
        # i.e., profit[i+1]
        # b) profit by buying at
        # price[i] and selling at
        #    max_price
        profit[i] = max(profit[i+1], max_price - price[i])
 
    # Get the maximum profit
    # with two transactions allowed
    # After this loop, profit[n-1]
    # contains the result
    min_price = price[0]
 
    for i in range(1, n):
 
        if price[i] < min_price:
            min_price = price[i]
 
        # Maximum profit is maximum of:
        # a) previous maximum,
        # i.e., profit[i-1]
        # b) (Buy, Sell) at
        # (min_price, A[i]) and add
        #  profit of other trans.
        # stored in profit[i]
        profit[i] = max(profit[i-1], profit[i]+(price[i]-min_price))
 
    result = profit[n-1]
 
    return result

print(maxProfit(arr, len(arr)))

# 20
# 9
# 1
# 10  - 9
# 4
# 5 - 10
# 9 -14
# 2
# 10 -22
# 0
# 5 - 27
# 7 - 29
# 7
# 8 - 30
# 5 
# 0 
# 6 - 36
# 0
# 8 - 44
# 8 
# 0 

