# Given a mxn grid, how many ways can I go from the start (0,0) to the end (m,n) by just moving RIGHT or DOWN
# Time complexity = O(m*n)
# Space complexity = O(m*n)

def gridTraveller_tab(rows, cols):
    table = [[0] * (cols+1) for i in range(rows+1)]

    table[1][1] = 1

    for i in range(rows+1):
        for j in range(cols+1):
            if(j+1 <= cols):
                table[i][j+1] += table[i][j]
            if(i+1 <= rows):
                table[i+1][j] += table[i][j]
    
    return table[rows][cols]

if __name__ == "__main__":
    m = int(input("Enter number of rows: "))
    n = int(input("Enter number of cols: "))

    print(f"Number of ways to travel from (1,1) to ({m},{n}): {gridTraveller_tab(m,n)}")