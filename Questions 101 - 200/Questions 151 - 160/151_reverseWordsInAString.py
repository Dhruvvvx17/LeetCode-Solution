def reverseWords(s: str) -> str:
    
    s = s.strip().split()
    
    res = " ".join(s[::-1])
        
    return res

if __name__ == "__main__":
    s = input("Enter a string: ")
    print(f"Reversed string: {reverseWords(s)}")