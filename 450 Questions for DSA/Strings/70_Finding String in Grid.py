class Solution:
        def __init__(self):
                self.R = None
                self.C = None
                self.dir = [[-1, 0], [1, 0], [1, 1],
                        [1, -1], [-1, -1], [-1, 1],
                        [0, 1], [0, -1]]
                
        def patternMatch(self, grid, row, col, word):
                if grid[row][col] != word[0]:
                        return False
                        
                for x,y in self.dir:
                        #Look for matches in other directions
                        #Initialize new directions
                        rd = row+x
                        cd = col+y
                        flag = True
                        for k in range(1,len(word)):
                                #Check for out of bounds
                                if(0<=rd<self.R and 0<=cd<self.C and word[k] == grid[rd][cd]):
                                        rd+=x
                                        cd+=y
                                else:
                                        flag = False
                                        break
                        if flag == True:
                                return True
                return False



        
        def searchWord(self, grid, word):
                self.R = len(grid)
                self.C = len(grid[0])

                for row in range(self.R):
                        for col in range(self.C):
                                if self.patternMatch(grid, row, col, word):
                                        print("Pattern found at", row, ",", col)
                


if __name__=='__main__':
    grid = ["GEEKSFORGEEKS",
            "GEEKSQUIZGEEK",
            "IDEQAPRACTICE"]
    gfg = Solution()
    gfg.searchWord(grid, 'GEEKS')
    print('')
    gfg.searchWord(grid, 'EEE')
