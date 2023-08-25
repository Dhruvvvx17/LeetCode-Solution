
def simplifyPath(path: str) -> str:
    
    stack = []
    for token in path.split("/"):
        
        if token == "." or token=="":
            pass
        elif token=="..":
            if len(stack)>0:
                stack.pop()
        else:
            stack.append(token)
            
    return "/" + "/".join(stack)

if __name__ == "__main__":
    s = input("Enter the absolute path: ")
    print(f"Canonical path = ",simplifyPath(s))