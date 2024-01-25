def decodeString(s):
    
    stack = []
    currString = ''
    currNum = ''

    for ch in s:

        if ch == "[":
            stack.append(currString)
            stack.append(currNum)
            currNum = ''
            currString = ''

        elif ch == "]":
            num = int(stack.pop())
            prevString = stack.pop()

            currString = prevString + num * currString

        elif ch.isdigit():
            currNum += ch

        else:   
            currString += ch

    return currString

if __name__ == "__main__":

    s = "3[a]2[b2[cd]]"

    print(f"Decoded string: {decodeString(s)}")