def longestCommonSubsequence(text1: str, text2: str) -> int:

    # entire dp table m * n where m and n are lengths of string + 1
    dp = [[0 for j in range(len(text2)+1)] for i in range(len(text1)+1)]

    # iterate over one string
    for i in range(len(text1)-1, -1, -1):

        # j -> 2 - 0
        for j in range(len(text2)-1, -1, -1):
            # if there is match look diagonal
            if(text1[i] == text2[j]):
                dp[i][j] = 1 + dp[i+1][j+1]
            # if not take max of bottom and down
            else:
                dp[i][j] = max(dp[i+1][j], dp[i][j+1])

    return dp[0][0]


def longestCommonSubsequenceOptimized(text1: str, text2: str) -> int:

    # one row to store previous results
    old_row = [0 for x in range(len(text2)+1)]

    # iterate over one string
    for i in range(len(text1)-1, -1, -1):

        # one row to store the new results
        new_row = [0 for y in range(len(text2)+1)]

        # iterate over the other string
        for j in range(len(text2)-1, -1, -1):

            # if there is a match 1 + diagonal value
            if(text1[i] == text2[j]):
                new_row[j] = 1 + old_row[j+1]
            # else max of left and down
            else:
                new_row[j] = max(old_row[j], new_row[j+1])

        old_row = new_row

    return old_row[0]


if __name__ == "__main__":

    text1 = input("Enter text 1: ")
    text2 = input("Enter text 2: ")

    print(
        f"Longest common subsequence is : {longestCommonSubsequence(text1, text2)}")

    print(
        f"Longest common subsequence (using Optimized algo) is : {longestCommonSubsequenceOptimized(text1, text2)}")
