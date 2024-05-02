# give nxn board, what are the possible placements of n queens so no one can attack the other
from typing import List

def solveNQueens(n: int) -> List[List[str]]:
    
    # bookkeeping
    cols = set()
    posDiag = set()
    negDiag = set()
    board = [["."] * n for _ in range(n)]
    res = []

    def backtracking(row):
        # filled all n queens in valid positons
        if row == n:
            currBoard = ["".join(r) for r in board]
            res.append(currBoard)
            return

        for col in range(n):

            # invalid positions
            if col in cols or (row + col) in negDiag or (row - col) in posDiag:
                continue

            # potentially valid
            else:
                # update states
                cols.add(col)
                posDiag.add(row - col)
                negDiag.add(row + col)
                board[row][col] = "Q"

                # check next row
                backtracking(row+1)

                # return to prev state - 'backtrack'
                board[row][col] = "."
                cols.remove(col)
                posDiag.remove(row - col)
                negDiag.remove(row + col)

        return
    
    backtracking(0)
    return res

if __name__ == "__main__":
    n = int(input("Enter n: "))

    res = solveNQueens(n)

    print(f"Number of solutions: {len(res)}")