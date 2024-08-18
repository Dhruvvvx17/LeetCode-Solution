# very intuitive dp

def minPathSum(grid):

    ROWS = len(grid)
    COLS = len(grid[0])

    dp = [[0] * COLS for _ in range(ROWS)]

    dp[0][0] = grid[0][0]

    # base case
    for c in range(1, COLS):
        dp[0][c] = grid[0][c] + dp[0][c-1]
    
    # base case
    for r in range(1, ROWS):
        dp[r][0] = grid[r][0] + dp[r-1][0]

    # populate the dp table
    for r in range(1, ROWS):
        for c in range(1, COLS):
            dp[r][c] = grid[r][c] + min(dp[r-1][c], dp[r][c-1])

    return dp[ROWS-1][COLS-1]

if __name__ == "__main__":
    grid = [[1,3,1],[1,5,1],[4,2,1]]

    print(f"Minimum path sum = {minPathSum(grid)}")