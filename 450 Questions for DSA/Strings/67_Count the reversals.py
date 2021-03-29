import math
for _ in range(int(input())):
    stack = []
    brackets = input()
    # if brackets[0] == '}':
        # stack.append('}')
    for i in range(len(brackets)):
        # print('The bracket is = ', brackets[i])
        if brackets[i] == '{':
            stack.append('{')
        if brackets[i] == '}':
            if len(stack)!=0 and stack[-1] == '{':
                stack.pop()
            else:
                stack.append('}')
        # print('The stack is = ', stack)
    if len(stack)%2!=0:
        print(-1)
    else:
        count_open = 0
        count_close = 0

        for i in range(len(stack)):
            if stack[i] == '{':
                count_open += 1
            if stack[i] == '}':
                count_close += 1
        print(math.ceil(count_open/2) + math.ceil(count_close/2))



        