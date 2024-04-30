def eraseOverlapIntervals(intervals):
    
    intervals.sort(key= lambda x: x[1])
    n = len(intervals)

    prev = 0
    valid = 1

    for i in range(1, n):
        if intervals[i][0] >= intervals[prev][1]:
            prev = i
            valid += 1
    
    return n - valid

if __name__ == "__main__":

    intervals = [[1,2],[2,3],[3,4],[1,3]]
    print(f"Number of intervals to remove: {eraseOverlapIntervals(intervals)}")