def isPlaindrome(S):
    if S == S[::-1]:
        return 1
    else:
        return 0
S = input()
print(isPlaindrome(S))