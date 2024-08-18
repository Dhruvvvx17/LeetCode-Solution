
def uniquePathsWithObstacles(grid):

    ROWS = len(grid)
    COLS = len(grid[0])

    if grid[0][0] or grid[ROWS-1][COLS-1]:
        return 0

    dp = [[0] * COLS for _ in range(ROWS)]

    # 1 in the grid -> obstacle | 0 in the grid -> free
    # 1 in the dpTable -> valid path | 0 in the dpTable -> no path
    dp[0][0] = 1 - grid[0][0]

    # base case
    for r in range(1, ROWS):
        dp[r][0] = 0 if grid[r][0] else dp[r-1][0]

    # base case
    for c in range(1, COLS):
        dp[0][c] = 0 if grid[0][c] else dp[0][c-1]

    # populate the dp table
    for r in range(1, ROWS):
        for c in range(1, COLS):
            if grid[r][c] == 1:
                dp[r][c] = 0
            else:
                dp[r][c] = dp[r][c-1] + dp[r-1][c]

    return dp[ROWS-1][COLS-1]

if __name__ == "__main__":
    grid = [[0,0,0],[0,1,0],[0,0,0]]

    print(f"Number of unique paths from top-left to bottom-right = {uniquePathsWithObstacles(grid)}")