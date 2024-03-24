pick = 6

def guess(num):
    if num > pick:
        return -1
    elif num < pick:
        return 1
    else:
        return 0

def guessNumber(n):
    start = 1
    end = n
    found = False
    iterations = 0

    while not found:
        mid = start + (end-start)//2

        iterations += 1
        
        check = guess(mid)
        if check == -1:
            end = mid - 1
        elif check == 1:
            start = mid + 1
        else:
            found = True
            break

    
    return mid, iterations

if __name__ == "__main__":

    res, i = guessNumber(100)
    print(f"{i} iterations to find {res} between 1 and 100")
