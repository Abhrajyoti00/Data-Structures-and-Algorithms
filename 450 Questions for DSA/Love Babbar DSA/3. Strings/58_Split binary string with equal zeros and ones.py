string = input()
cnt0 = 0
cnt1 = 0
sub = 0
for ele in string:
    if ele == '0':
        cnt0 += 1
    if ele == '1':
        cnt1 += 1
    if cnt0 == cnt1 and cnt0>0:
        sub += 1
        cnt0 = 0
        cnt1 = 0
if sub == 0:
    print(-1)
else:
    print("The no of substring possible = ", sub)