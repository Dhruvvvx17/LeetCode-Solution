def uniquePaths(m: int, n: int) -> int:

    # first temporary row
    # row of 1s -> because bottom will always be 1s (can only go right)
    old_row = [1] * n

    for i in range(m-1):
        new_row = [1] * n

        # update new row in terms of old_row[down] and new_row[right]
        # can ignore the last column as that will always be 1
        # go right to left
        for j in range(n-2, -1, -1):
            # curr cell = right + down
            new_row[j] = new_row[j+1] + old_row[j]

        old_row = new_row

    return old_row[0]


if __name__ == "__main__":
    m = int(input("Enter number of rows: "))
    n = int(input("Enter number of columns: "))

    print(f"Number of unique paths: {uniquePaths(m,n)}")
