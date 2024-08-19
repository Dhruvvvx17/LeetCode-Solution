def isInterleave(s1: str, s2: str, s3: str) -> bool:
    
    if len(s1) + len(s2) != len(s3):
        return False
    
    dp = [[False] * (len(s2) + 1) for _ in range(len(s1) + 1)]

    dp[len(s1)][len(s2)] = True

    for i in range(len(s1), -1, -1):
        for j in range(len(s2), -1, -1):

            if i < len(s1) and s1[i] == s3[i+j] and dp[i+1][j]:
                dp[i][j] = True

            if j < len(s2) and s2[j] == s3[i+j] and dp[i][j+1]:
                dp[i][j] = True
    
    return dp[0][0]

if __name__ == "__main__":
    s1 = input("Enter string 1: ")
    s2 = input("Enter string 2: ")
    s3 = input("Enter string 3: ")

    if(isInterleave(s1, s2, s3)):
        print(f"{s3} can be constructed from {s1} and {s2}")
    else:
        print(f"{s3} cannot be constructed from {s1} and {s2}")