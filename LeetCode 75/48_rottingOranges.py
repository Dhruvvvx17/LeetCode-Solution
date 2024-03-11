from collections import deque

def orangesRotting(grid):
    
    ROWS, COLS = len(grid), len(grid[0])
    iterations = 0
    fresh = 0

    queue = deque()

    for i in range(ROWS):
        for j in range(COLS):
            if grid[i][j] == 1:
                fresh += 1
            # mark initial rotten oranges
            elif grid[i][j] == 2:
                queue.append((i,j))

    directions = [(0,1), (0,-1), (1,0), (-1,0)]

    while len(queue) > 0 and fresh > 0:
        
        q_len = len(queue)

        for _ in range(q_len):
            pos = queue.popleft()
            cx = pos[0]
            cy = pos[1]

            for d in directions:

                nx, ny = cx + d[0], cy + d[1]
            
                # invalid position
                if nx < 0 or nx >= ROWS or ny < 0 or ny >= COLS or grid[nx][ny] != 1:
                    continue

                # previously fresh, now rotten 
                grid[nx][ny] = 2

                queue.append((nx, ny))
                fresh -= 1
        
        iterations += 1