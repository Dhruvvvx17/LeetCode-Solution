def wordBreak(s, wordDict):

    # dp stores the valid position to break string s
    dp = [False] * (len(s)+1)

    # out of bounds, base case
    dp[len(s)] = True

    for i in range(len(s)-1, -1, -1):
        for word in wordDict:

            if i + len(word) <= len(s) and s[i: i+len(word)] == word:
                dp[i] = dp[i+len(word)]

            if dp[i]:
                break

    return dp[0]


if __name__ == "__main__":

    s = "leetcode"

    wordDict = ["leet", "co", "code"]

    print(f"Possible to break the word? {wordBreak(s, wordDict)}")
