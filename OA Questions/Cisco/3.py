# Given a MxN matrix, traverse it in anti-clockwise direction and skip every other element.
# eg:
# 9 8 7 6
# 5 4 3 2
# 1 10 11 12
# 
# traversal: 9 -> 1 -> 11 -> 2 -> 7 -> 4

def find_last(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    directions = [(1,0), (0,1), (-1,0), (0,-1)] # down, right, up, left
    direction_index = 0
    curr_row, curr_col = 0, 0
    order = []

    while True:
        
        order.append(matrix[curr_row][curr_col])

        next_row, next_col = curr_row + directions[direction_index][0], curr_col + directions[direction_index][1]

        # switch directions
        if next_row < 0 or next_row >= rows or next_col < 0 or next_col >= cols or matrix[next_row][next_col] is None:
            direction_index = (direction_index + 1) % 4
            next_row, next_col = curr_row + directions[direction_index][0], curr_col + directions[direction_index][1]

        # if after switching directions, still out of bounds - end loop
        if next_row < 0 or next_row >= rows or next_col < 0 or next_col >= cols or matrix[next_row][next_col] is None:
            break

        matrix[curr_row][curr_col] = None
        curr_row, curr_col = next_row, next_col


    print("->".join(map(str, order)))

    # second last element
    if(len(order)%2 == 0):
        return order[-2]
    # last element
    else:
        return order[-1]


if __name__ == "__main__":
    matrix = [
        [9, 8, 7, 6],
        [5, 4, 3, 2],
        [1, 10, 11, 12]
    ]

    print(f"Last element to visit: {find_last(matrix)}")