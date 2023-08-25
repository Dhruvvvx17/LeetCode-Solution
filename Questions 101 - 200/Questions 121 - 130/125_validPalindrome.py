def isPalindrome(s: str) -> bool:
    
    temp = ""
    
    for char in s:
        if(char.isalpha()):
            temp += char.lower()
        elif(char.isdigit()):
            temp += char
            
    return temp == temp[::-1]

if __name__ == "__main__":
    s = input("Enter a string: ")
    if(isPalindrome):
        print("Palindrome")
    else:
        print("Not a Palindrome")