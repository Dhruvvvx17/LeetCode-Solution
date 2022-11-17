def pacificAtlantic(heights):

    COLS = len(heights[0])
    ROWS = len(heights)

    pac = set()
    atl = set()

    def dfs(r, c, visited, prevHeight):

        if((r, c) in visited or r < 0 or r == ROWS or c < 0 or c == COLS or heights[r][c] < prevHeight):
            return

        visited.add((r, c))
        dfs(r+1, c, visited, heights[r][c])
        dfs(r, c+1, visited, heights[r][c])
        dfs(r-1, c, visited, heights[r][c])
        dfs(r, c-1, visited, heights[r][c])

    for c in range(COLS):
        dfs(0, c, pac, heights[0][c])
        dfs(ROWS-1, c, atl, heights[ROWS-1][c])

    for r in range(ROWS):
        dfs(r, 0, pac, heights[r][0])
        dfs(r, COLS-1, atl, heights[r][COLS-1])

    # print(pac, atl)

    res = []
    for r in range(ROWS):
        for c in range(COLS):
            if (r, c) in pac and (r, c) in atl:
                res.append([r, c])

    return res


if __name__ == "__main__":

    heights = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [
        2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]

    res = pacificAtlantic(heights)

    print(res)
