# def wordBreak(wordList, word):
#     if word == '':
#         return True
#     else:
#         wordLen = len(word)
#         return any([(word[:i] in wordList) and wordBreak(wordList, word[i:]) for i in range(1, wordLen+1)])
    
def isPresent(line, dictionary):

    dp = [False for i in range(len(line)+1)]

    for i in range(1, len(line)+1):
        if dp[i] == False and line[:i] in dictionary:
            dp[i] = True
        
        if dp[i] == True:
            if i == len(line):
                return True
            
        for j in range(i+1, len(line)+1):
            if dp[j] == False and line[i:j] in dictionary:
                dp[j] = True
            
            if j == len(line) and dp[j] == True:
                return True
    return False

def wordBreak(line, dictionary):
    return isPresent(line, dictionary)
    # return isPresent(line, dictionary, 0, len(line), 0)



B = [ "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" ]
# A = "ilikesamsung"

# A = "iliketea"
A = "samsunglikei"

print(wordBreak(A, B))
