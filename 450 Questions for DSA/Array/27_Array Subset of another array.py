from collections import Counter
def isSubset( a1, a2, n, m):
    a=Counter(a2)-Counter(a1)
    if len(a)==0:
        return ("Yes")
    else:
        return ("No")

a1 = [10, 5, 2, 23, 19]
a2 = [19, 5, 3]
print(isSubset(a1,a2, len(a1), len(a2)))