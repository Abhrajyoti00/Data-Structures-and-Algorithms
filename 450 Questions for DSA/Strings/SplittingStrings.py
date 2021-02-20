def isPossible(string):
    if len(string) == 1:
        return False
    gap = 1
    # while(gap<len(string)):
    i = 0
    while((gap<len(string)) and (i<len(string))):
        if(i+gap < len(string)):
            s1 = string[i:i+gap]
            # print('s1 = ', s1)

            no_to_be = int(s1) + 1
            len_of_no_to_be = len(str(no_to_be))
            if (i+gap+len_of_no_to_be) <= len(string):
                s2 = string[i+gap:i+gap+len_of_no_to_be]
                # print('s2 = ', s2)
                if no_to_be == int(s2):
                    i = i+gap
                    gap = len_of_no_to_be
                    if(i+gap>=len(string)):
                        return True
                    else:
                        continue
                else:
                    gap+=1
                    i=0
            else:
                gap+=1
                i = 0

        else:
            gap+=1
            i = 0
    return False

string = input()

if(isPossible(string)):
    print('Possible')
else:
    print("Not Possible")
        