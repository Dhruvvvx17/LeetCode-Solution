
def minimumTotal(triangle):

    dp = triangle[0]

    for level in range(1, len(triangle)):
        curr = []
        for idx in range(level+1):
            if idx == 0:
                curr.append(triangle[level][idx] + dp[idx])
            elif idx == level:
                curr.append(triangle[level][idx] + dp[idx-1])
            else:
                curr.append(triangle[level][idx] + min(dp[idx], dp[idx-1]))       
        dp = curr

    return min(dp)


if __name__ == "__main__":
    triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]

    res = minimumTotal(triangle)
    print(f"The minimum total to go from top to bottom: {res}")