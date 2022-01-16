def addBinary(a: str, b: str) -> str:
    a = int(a,2)
    b = int(b,2)
    
    return(bin(a+b)[2:])

if __name__ == "__main__":
    print("Enter 1st bin string: ",end="")
    a = input()
    print("Enter 2nd bin string: ",end="")
    b = input()

    print(f"Sum of binary strings = {addBinary(a,b)}")