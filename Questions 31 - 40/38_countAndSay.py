def countAndSay(n: int) -> str:
    
    if(n==1 or n==0):
        return "1"
    if(n==2):
        return "11"
    
    res = "11"
    i = 3
    while(i<=n):
        temp = ""
        digit = res[0]
        j = 1
        count = 1
        while(j<len(res)):
            if(res[j]==digit):
                count += 1
            else:
                temp += str(count) + str(digit)
                digit = res[j]
                count = 1
            j+=1
            
        if(count>0):
            temp += str(count) + str(digit)

        res = temp  
        i += 1
                
    return res


if __name__ == "__main__":
    print("Enter the sequence number: ",end="")
    n = int(input())

    print(f"The {n}th sequence number is: {countAndSay(n)}")
