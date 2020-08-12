def myAtoi(mystr: str) -> int:
    
    # Strip the string of any whitespace
    mystr = mystr.strip()
    if(len(mystr)==0):
        return(0)

    isPositive = True
    start_index = 0

    # Check if there exists a leading minus sign 
    if(mystr[0]=="-"):
        isPositive = False
        start_index = 1
        
    # Check if there exists a leading plus sign     
    elif(mystr[0]=="+"):
        isPositive = True
        start_index = 1

    #Obtain the numeric part of the string
    numeric_string = ""
    for ch in mystr[start_index:]:
        if(ch.isdigit()):
            numeric_string += ch
        else:
            break
    
    #If no numeric part exists, then return 0        
    if(len(numeric_string)==0):
        return(0)
    
    #Else convert the string to number
    else:
        res = 0
        zero_factor = len(numeric_string)-1
        for num in numeric_string:
            res += ((ord(num) - ord('0'))*(10**zero_factor))
            zero_factor -= 1
                    
    if not(isPositive):
        res = 0 - res
    print(res)
        
    # If negative overflow
    if(res<(0 - 2**31)):
        return (0 - 2**31)
    
    # If positive overflow 
    elif(res>(2**31 - 1)):
        return (2**31 - 1)
    
    else:
        return(res)

if __name__ == "__main__":
    print("Enter a number: ",end="")
    s = input()
    print("Number taken in string format: ",s)

    print(f"Using ATOI, result = {myAtoi(s)}")