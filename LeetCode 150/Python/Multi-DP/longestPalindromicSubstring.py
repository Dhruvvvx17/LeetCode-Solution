# Brute force - O(n^3)
# Center-expand-outward method - O(n^2) 
# [n for each letter considered as the center] * [n for expansion on either side]

def longestPalindrome(s: str) -> str:
    res = ""
    resLen = 0

    for i in range(len(s)):
        # odd length
        l, r = i, i
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        # correct the last expansion
        l += 1
        r -= 1
        if r - l + 1 > resLen:
            resLen = r - l + 1
            res = s[l: r+1]

        # even length
        l, r = i, i + 1
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        # correct the last expansion
        l += 1
        r -= 1
        if r - l + 1 > resLen:
            resLen = r - l + 1
            res = s[l: r+1]
    
    return res

if __name__ == "__main__":
    s = input("Enter string: ")
    res = longestPalindrome(s)
    print(f"Longest palindromic substring is {res} of length = {len(res)} ")