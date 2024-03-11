def nearestExit(maze, entrance):
    
    R = len(maze)
    C = len(maze[0])

    sx, sy = entrance
    q = []
    INF = 10 ** 20
    distance = [[INF] * C for _ in range(R)]

    def enqueue(x, y, d):
        distance[x][y] = d
        q.append((x,y,d))

    enqueue(sx, sy, 0)

    directions = [(0,1), (0,-1), (1,0), (-1,0)]

    while len(q) > 0:
        x, y, d = q.pop(0)

        if x == 0 or x == R-1 or y == 0 or y == C-1:
            if not(x == sx and y == sy):
                return d

        for dx, dy in directions:
            nx, ny = x + dx, y + dy

            if 0 <= nx < R and 0 <= ny < C and maze[nx][ny] != "+" and distance[nx][ny] == INF:
                enqueue(nx, ny, d+1)

    return -1


if __name__ == "__main__":
    maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]
    entrance = [1,2]

    res = nearestExit(maze, entrance)

    print(f"Nearest exit is at a distance of {res}")