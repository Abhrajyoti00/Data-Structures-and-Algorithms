class Solution:
    def countAndSay(self, n):
        count_and_say = [0 for i in range(n+2)]
        count_and_say[1] = 1
        count_and_say[2] = 11
        for i in range(3,n+1):
            prev = count_and_say[i-1]
            str_prev = str(prev)
            count = 1
            temp_string = ''
            for j in range(0,len(str_prev)-1):
                if str_prev[j] == str_prev[j+1]:
                    count += 1
                else:
                    temp_string+= str(count)+str(str_prev[j])
                    count = 1
            temp_string+= str(count)+str(str_prev[j+1])
            count_and_say[i] = int(temp_string)
        return str(count_and_say[n])

sol = Solution()
print(sol.countAndSay(14))


