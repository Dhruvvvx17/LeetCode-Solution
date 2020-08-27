def lengthOfLastWord(s: str) -> int:
    
    s = s.strip()
    if(len(s)==0):
        return 0
    
    count = 0
    i = len(s)-1
    while(i>=0):
        
        if(s[i]==" "):
            break
        
        count += 1
        i-=1
        
    return count

if __name__ == "__main__":
    print("Enter string: ",end="")
    s = input()

    print(f"Length of last word in the string \"{s}\" = {lengthOfLastWord(s)}")