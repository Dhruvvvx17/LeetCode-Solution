from typing import List

def dfs(s, temp, res):
    # if end of string is reached, append current result to global result
    if not s:
        res.append(temp)
    
    # iterative solution - check if every substring is a palindrome
    for i in range(1,len(s)+1):
        if(isPalindrome(s[:i])):
            dfs(s[i:], temp+[s[:i]], res)


def isPalindrome( p):
    return p == p[::-1]
        

def partition(s: str) -> List[List[str]]:
    res = []
    dfs(s, [], res)
    return res


if __name__ == "__main__":
    s = input("Enter a string: ")
    res = partition(s)

    print(f"{len(res)} palindromes found in {s}: ")
    for palindrome in res:
        print(palindrome)