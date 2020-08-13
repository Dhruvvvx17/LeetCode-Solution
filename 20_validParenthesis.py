# Using a basic stack with multiple border case checks

def isValid(s: str) -> bool:
    
    if(len(s)==0):
        return True
    elif(len(s)%2==1):
        return False
    
    matching_set = set([("(",")"), ("[","]"),("{","}")])  
    opening_brackets_set = set('({[')
    closing_brackets_set = set(']})')
    stack = []
    last_opened = ""        

    for bracket in s:
        
        if( len(stack)==0 and bracket in closing_brackets_set ):
            return False
        
        # Opening bracket
        if(bracket in opening_brackets_set):
            stack.append(bracket)

        
        #Closing bracket
        else:
            last_opened = stack.pop()
            if not ((last_opened,bracket) in matching_set):
                return False
                
    # Check if stack is empty
    if(len(stack)==0):
        return True        
    else:
        return False

if __name__ == "__main__":
    print("Enter a sequence of brackets: ",end="")
    s = input()
    if(isValid(s)):
        print("The given sequence is valid")
    else:
        print("The given sequence is invalid")