def reverse(x: int) -> int:        
    isPositive = True
    if(x<0):
        isPositive = False
        x = 0 - x
    
    zero_factor = len(str(x)) - 1
    divident = x
    res = 0
    
    while(divident>9):
        rem = divident % 10
        res += rem*(10**zero_factor)
        zero_factor -= 1
        divident = divident // 10
    
    res += divident
    
    if(isPositive):
        if(res>(2**31 - 1)):
            return(0)
        else:
            return(res)
    else:
        if((0-res)<(0 - 2**31)):
            return(0)
        else:
            return(0-res)


if __name__ == "__main__":
    print("Enter a number (with a + or - or no sign): ",end="")
    x = int(input())
    print(f"Reversed integer = {reverse(x)}")