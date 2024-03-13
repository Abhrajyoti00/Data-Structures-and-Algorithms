def fact(n):
    factorial = [0 for i in range(n+2)]
    factorial[0] = 1
    factorial[1] = 1
    for i in range(1,n+1):
        factorial[i] = i*factorial[i-1]
    return factorial[n]


for _ in range(int(input())):
    n = int(input())
    print(fact(n))