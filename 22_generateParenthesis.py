# Simple check: number of right brackets should never be more that the number of left brackets

def generateParenthesis(n):
    
    if(n==0):
        return([""])
    if(n==1):
        return(["()"])
    
    # List of tuple, every tuple indicates the bracket string, then number of left brackets and right brackets
    possible_combinations = [('(',1,0)]
    valid_combinations = []
    
    while possible_combinations:
        x,l,r = possible_combinations.pop()
        
        # This is an invalid combination, as it is already popped, won't go back in the possible_combinations
        if(l-r<0 or l>n or r>n):
            continue
            
        else:
            if(l==n and r==n):
                valid_combinations.append(x)
            possible_combinations.append((x+'(', l+1, r))         #Add a left bracket to existing sequence
            possible_combinations.append((x+')', l, r+1))         #Add a right bracket to existing sequence
        
        # print(possible_combinations)
    return(valid_combinations)

if __name__ == "__main__":
    print("Enter number of bracket pairs: ",end="")
    n = int(input())
    print(f"All valid combinations with {n} bracket pairs are: {generateParenthesis(n)}")    