# Tricky DP

def maximalSquare(matrix) -> int:
    
    ROWS = len(matrix)
    COLS = len(matrix[0])
    cache = {}

    def helper(r, c):
        if r >= ROWS or c >= COLS:
            return 0
        
        if (r, c) not in cache:
            down = helper(r+1, c)
            right = helper(r, c+1)
            diag = helper(r+1, c+1)

            if matrix[r][c] == "1":
                cache[(r, c)] = 1 + min(right, down, diag)
            else:
                cache[(r, c)] = 0

        return cache[(r, c)]
    
    helper(0,0)
    return max(cache.values())**2

if __name__ == "__main__":
    matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]

    print(f"Area of the maximal square = {maximalSquare(matrix)}")