def printSequence(arr, input):
    number = []
    for char in input:
        if char == ' ':
            number.append("0")
        else:
            number.append(str[ord(char) - ord("A")])
    return ("".join(number))




str = ["2", "22", "222",
       "3", "33", "333",
       "4", "44", "444",
       "5", "55", "555",
       "6", "66", "666",
       "7", "77", "777", "7777",
       "8", "88", "888",
       "9", "99", "999", "9999" ]
  
# input = "GEEKSFORGEEKS";
input = "HELLO WORLD";
print( printSequence(str, input))