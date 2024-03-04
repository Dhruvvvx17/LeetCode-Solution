
def canVisitAllRooms(rooms) -> bool:
    
    n = len(rooms)
    visited = [False]*n

    queue = []
    for key in rooms[0]:
        queue.append(key)

    visited[0] = True

    while(len(queue) > 0):
        key = queue[0]
        queue.pop(0)

        if not(visited[key]):
            for r in rooms[key]:
                queue.append(r)

        visited[key] = True

    if False in visited:
        return False
    else:
        return True


if __name__ == "__main__":
    rooms = [[1,3],[3,0,1],[2],[0]]
    res = canVisitAllRooms(rooms)

    if(res):
        print("Can visit all rooms")
    else:
        print("Cannot visit all rooms")
        