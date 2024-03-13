# LoL = ListofList
def merge(LoL):
        newLoL = []
        LoL = sorted(LoL)

        for i in range(0,len(LoL)):
            if not newLoL or LoL[i][0] > newLoL[-1][1]:
                newLoL.append(LoL[i])
            else:
                newLoL[-1][1] = max(LoL[i][1], newLoL[-1][1]);
                
        return newLoL


# LoL = ListofList
# def merge(LoL):
#         # newLoL = []
#         LoL = sorted(LoL)
#         index = 0
#         for i in range(1,len(LoL)):
#             if LoL[index][0] > LoL[i][1]:
#                 index+=1
#                 LoL[index] = LoL[i]

#             else:
#                 LoL[index][1] = max(LoL[index][1]), LoL[i][1]
#                 LoL[index][0] = min(LoL[index][0]), LoL[i][0]
                
#         return LoL


intervals = [[1,3],[8,10],[2,6],[15,18]]
# intervals = [[1,4],[4,5]]
# intervals = [[1,3]]
# intervals = [[1,4],[5,6]]

print(merge(intervals))

