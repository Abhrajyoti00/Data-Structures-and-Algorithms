class Solution:
    def minimumNumberOfSwaps_On2O1(self,S):
        count = 0
        sum = 0
        i = 0
        while(i<len(S)):
            found_a_j = 0
            if S[i] == '[':
                count += 1
            if S[i] == ']':
                count -= 1
            if count<0:
                # print('S = ', S)
                # print("sum = ", sum)
                for  j in range(i+1, len(S)):
                    if S[j] == '[':
                        found_a_j = 1
                        sum += j-i
                        temp = S[j]
                        break
                if found_a_j == 0:
                    # print("Came in Check")
                    return sum
                else:
                    # print("i = ", i, " j = ", j)
                    list1 = list(S)
                    for k in range(j,i,-1):
                        
                        # print(" k = ", k, "list1 = ", list1)

                        list1[k] = list1[k-1]
                        # print("list1 = ", list1)
                    list1[i] = temp
                    # print("Final list1 = ", list1)
                    S = ''.join(list1)
                    count = 0
                    i+=1
                    # continue
            i+=1
        return sum

    def minimumNumberOfSwaps_OnOn(self,S):
        count = 0
        ans = 0
        i = 0
        list_of_open_positions = []
        for i in range(len(S)):
            if S[i] == '[':
                list_of_open_positions.append(i)
        
        iterator_of_open_positions = 0
        string_list = list(S)
        for i in range(len(string_list)):
            # print(' i = ', i, "string_list = ", string_list, " count = ", count)
            if string_list[i] == '[':
                count += 1
                iterator_of_open_positions += 1
            elif string_list[i] == ']':
                count -= 1
            if count<0:
                ans +=  list_of_open_positions[iterator_of_open_positions] - i
                string_list[i], string_list[list_of_open_positions[iterator_of_open_positions]] = string_list[list_of_open_positions[iterator_of_open_positions]], string_list[i]
                count = 1 #We made this 1 as the next character is a sure shot ']', so we skip that one.
                iterator_of_open_positions += 1
        # print(string_list)
        return ans

    def minimumNumberOfSwaps_OnO1(self,S):
        swap = 0
        imbalance = 0
        cLeft = 0
        cRight = 0
        for i in range(len(S)):
            if S[i] == '[':
                cLeft += 1
                if imbalance>0:
                    swap += imbalance #swaps count is last swap count + total number of imbalanced brackets
                    imbalance-=1
            elif S[i] == ']':
                cRight += 1
                imbalance = cRight - cLeft
        return swap

sol = Solution()
S = "]][["
# S = "[]][]["
# S = "[[][]]"
# print(sol.minimumNumberOfSwaps_On2O1(S))
# print(sol.minimumNumberOfSwaps_OnOn(S))
print(sol.minimumNumberOfSwaps_OnO1(S))