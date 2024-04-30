def findMinArrowShots(points) -> int:
    
    points = sorted(points, key = lambda x: x[0])
    res = len(points)
    prev = points[0]

    for i in range(1, len(points)):
        curr = points[i]

        if curr[0] <= prev[1]:
            res -= 1
            prev = [curr[0], min(curr[1], prev[1])]
        else:
            prev = curr

    return res

if __name__ == "__main__":

    points = [[10,16],[2,8],[1,6],[7,12]]
    print(f"Minimum number of arrows to pop all baloons = {findMinArrowShots(points)}")