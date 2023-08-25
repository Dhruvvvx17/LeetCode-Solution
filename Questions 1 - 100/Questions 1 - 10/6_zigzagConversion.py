def convert(s: str, numRows: int) -> str:
    
    # If number of rows = 1, no rearrangement
    if(numRows==1):
        return(s)

    # If string length = 1, no rearrangement
    if(len(s)==1):
        return(s)
    
    res = ""
    row = 0
    length = len(s)
    jump = (numRows-1) * 2
    
    while(row < numRows):
        index = row
            
        # FIRST ROW
        if(row==0):
            while(index<length):
                res += s[index]
                index += jump
            
        # LAST ROW
        elif(row==numRows-1):
            while(index<length):
                res += s[index]
                index += jump
        
        # INTERMEDIATE ROW
        else:
            while(index<length):
                temp = s[index]
                
                # Checking if string index is valid (either a vertical or diagonal line)
                if(index+jump < length or index+jump-(row*2) < length):
                    index += jump
                    temp += s[index - row*2]
                    
                else:
                    res += temp
                    break

                res += temp
        
        row += 1
        
    return res


if __name__ == "__main__":
    print("Enter string: ",end="")
    s = input()
    print("Enter number of rows: ",end="")
    n = int(input())
    res = convert(s,n)
    print(f"String obtained from zig-zag pattern = {res}")
