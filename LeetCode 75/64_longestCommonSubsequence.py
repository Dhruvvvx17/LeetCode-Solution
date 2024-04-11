def longestCommonSubsequence(text1: str, text2: str) -> int:
    l1 = len(text1)
    l2 = len(text2)
    table = [[0 for _ in range(l2+1)] for _ in range(l1+1)]

    for i in range(l1):
        for j in range(l2):
            if text1[i] == text2[j]:
                table[i+1][j+1] = 1 + table[i][j]
            else:
                table[i+1][j+1] = max(table[i][j+1], table[i+1][j])

    return table[l1][l2]

if __name__ == "__main__":
    text1 = "abcdefghijk"
    text2 = "acel"

    print(f"Length of LCS: {longestCommonSubsequence(text1, text2)}")