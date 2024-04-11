def uniquePaths(m: int, n: int) -> int:
    rows = m
    cols = n
    table = [[1 for _ in range(cols)] for _ in range(rows)]

    for i in range(1,m):
        for j in range(1, n):
            table[i][j] = table[i-1][j] + table[i][j-1]
    
    return table[m-1][n-1]

if __name__ == "__main__":
    m = 7
    n = 3

    print(f"Number of unique paths = {uniquePaths(m, n)}")