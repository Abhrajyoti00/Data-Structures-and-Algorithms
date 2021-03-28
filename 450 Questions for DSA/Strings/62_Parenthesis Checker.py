class Solution:
    
    
    #User function Template for python3
    '''
    Function Arguments :
    		@param  : s (given string containing parenthesis) 
    		@return : boolean True or False
    '''
    def ispar(self,x):
        if x[0] == ')' or x[0] == ']' or x[0] == '}':
            return False
        stack = []
        for bracket in x:
            if bracket == '(' or bracket == '[' or bracket == '{':
                stack.append(bracket)
            elif bracket == ')' and len(stack)!=0:
                top = stack.pop()
                if top!='(':
                    return False
            elif bracket == '}' and len(stack)!=0:
                top = stack.pop()
                if top!='{':
                    return False
            elif bracket == ']' and len(stack)!=0:
                top = stack.pop()
                if top!='[':
                    return False
        if len(stack)!=0:
            return False
        return True


sol = Solution()

exp =  "[()]{}{[()()]()}"
exp = "[(])"
print(sol.ispar(exp))

                