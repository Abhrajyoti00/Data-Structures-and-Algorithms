#User function Template for python3

def reverseWord(s):
    return s[::-1]


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input()
        print(reverseWord(s))