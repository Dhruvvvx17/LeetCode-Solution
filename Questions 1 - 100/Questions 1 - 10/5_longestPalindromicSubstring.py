# Longest palindromic "substring" using bottom up dynamic programming approach

def longestPalindrome(s: str) -> str:

    if(len(s)==0):
        return ""

    if(len(s)==1):
        return s
    
    n = len(s)
    dp = [[0]*n for _ in range(n)]
    res = ""
    global_max_len = 0
    
    # All diagonal elements are a palindrome of length = 1
    for i in range(n):
        dp[i][i] = 1
        

    for i in range(n-1,-1,-1):
        for j in range(i,n):
            
            # for 2 or 3 character strings
            if(s[i]==s[j] and j-i+1 <=3):
                dp[i][j] = j-i+1
            
            # for strings with length > 3
            elif(s[i]==s[j] and dp[i+1][j-1]):
                dp[i][j] = 2 + dp[i+1][j-1]
            
            else:
                dp[i][j] = 0

            if(dp[i][j] > global_max_len):
                global_max_len = dp[i][j]
                res = s[i:j+1]
                
    return(res)


if __name__ == "__main__":
    print("Enter string: ",end="")
    s = input()
    res = longestPalindrome(s)
    print(f"Longest palindromic substring = {res}")