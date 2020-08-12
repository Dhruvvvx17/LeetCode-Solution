def isPalindrome(x: int) -> bool:

    if(x==0): return True

    # Negative number or number divisible by 10
    if(x<0 or x%10==0): return False

    rev = 0
    while(x>rev):
        rev = rev*10 + (x%10)
        x = x//10
        
    if(rev == x or rev//10 == x):
        return True
    else:
        return False
    
    """
    #Alternative:
    return(str(x)==str(x)[::-1])
    """

if __name__ == "__main__":
    print("Enter a number: ",end="")
    x = int(input())
    if(isPalindrome(x)):
        print(f"{x} is a palindrome")
    else:
        print(f"{x} is not a palindrome")
