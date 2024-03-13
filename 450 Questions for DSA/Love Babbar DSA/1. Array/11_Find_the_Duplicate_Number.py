# O(n) Time, O(n) Space :-

# def findDuplicate(List):
#     myDict = {}
#     for _ in List:
#         if _ in myDict:
#             myDict[_]+=1
#         else:
#             myDict[_] = 1
#     for ele in myDict:
#         if  myDict[ele]>1:
#             return ele

# O(n) Time, O(n) Space : Floyd's Algo

def findDuplicate(List):
    slow = fast = List[0]
    while True:
        slow = List[slow]
        fast = List[List[fast]]
        if (slow == fast):
            break

    fast = List[0]
    while(slow != fast):
        slow = List[slow]
        fast = List[fast]

    return fast


List = list(map(int, input().split()))
print(findDuplicate(List))
