def romanToDecimal(str):
    dict = {'I': 1, 'V': 5,'X': 10,'L': 50,'C': 100,'D': 500,'M': 1000}
    sum = dict[str[0]]
    for i in range(1,len(str)):
        prev = str[i-1]
        curr = str[i]
        if dict[prev]<dict[curr]:
            sum += dict[curr] - 2*dict[prev]
        else:
            sum += dict[curr]
    print(sum)

romanToDecimal(input())

