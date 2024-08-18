def minDistance(word1: str, word2: str) -> int:

    ROWS = len(word1)+1
    COLS = len(word2)+1

    dp = [[0]*COLS for _ in range(ROWS)]

    for r in range(1, ROWS):
        dp[r][0] = r

    for c in range(1, COLS):
        dp[0][c] = c
    
    for r in range(1, ROWS):
        for c in range(1, COLS):
            ch1 = word1[r-1]
            ch2 = word2[c-1]

            if ch1 == ch2:
                dp[r][c] = dp[r-1][c-1]
            else:
                dp[r][c] = 1 + min(dp[r][c-1], dp[r-1][c], dp[r-1][c-1])
                
    return dp[ROWS-1][COLS-1]

if __name__ == "__main__":
    word1 = input("Enter word 1: ")
    word2 = input("Enter word 2: ")

    print(f"Minimum edit distance to transform {word1} to {word2} is: {minDistance(word1, word2)}")