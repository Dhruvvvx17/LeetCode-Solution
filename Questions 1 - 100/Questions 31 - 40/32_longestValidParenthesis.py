def longestValidParentheses(s: str) -> int:
    
    stack = [0]
    longest_valid_len = 0
    
    for b in s:
                        
        if(b=="("):
            stack.append(0)
        
        else:
            if(len(stack)>1):
                val = stack.pop()
                stack[-1] += val + 2
                longest_valid_len = max(longest_valid_len,stack[-1])
            else:
                stack = [0]
    
    return(longest_valid_len)


if __name__ == "__main__":
    print("Enter bracker sequence: ",end="")
    b = input()
    print(f"Longest valid parentheses length = {longestValidParentheses(b)}")