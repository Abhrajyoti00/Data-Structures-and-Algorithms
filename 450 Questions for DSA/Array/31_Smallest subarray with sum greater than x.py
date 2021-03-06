def sb( a, n, x):
    if max(a)>x:
        return 1
    else:
        start = 0
        end = 0
        sum = a[0]
        count = 1
        min_count = 100000001
        while(start<=end and end<n):
            if sum>x:
                min_count = min(min_count, count)
                sum-=a[start]
                count-=1
                start+=1
                
    
            elif sum<=x:
                end+=1
                if end>=n:
                    break
                else:
                    sum+=a[end]
                    count+=1
            

    return min_count
# A = [1, 4, 45, 6, 0, 19]
A = [1, 10, 5, 2, 7]
# X = 51
X = 9
print(sb(A, len(A), X))



