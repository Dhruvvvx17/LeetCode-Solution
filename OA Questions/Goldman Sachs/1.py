# Given two strings containing lowercase english letters and the character '#' which represents backspace key, determine
# if the two final strings are equal. Return 1 if equal and 0 if not.
# Eg - 
# s1 = 'axx#bb#c'
# s2 = 'axbd#c#c'

# output = 1 because the strings boil down to "axbc" and "axbc"

def compareStrings(s1, s2):

    s1_new = ""
    for ch in s1:
        if ch != "#":
            s1_new += ch
        else:
            if len(s1_new) > 0:
                # backspace
                s1_new = s1_new[:-1]

    s2_new = ""
    for ch in s2:
        if ch != "#":
            s2_new += ch
        else:
            if len(s2_new) > 0:
                # backspace
                s2_new = s2_new[:-1]

    if(s1_new == s2_new):
        return 1
    return 0

if __name__ == "__main__":
    s1 = input("Enter string s1: ")
    s2 = input("Enter string s2: ")

    if(compareStrings(s1, s2)):
        print("Strings are equal")
    else:
        print("Strings are not equal")