def countBits(n):
    
    if n == 0:
        return [0]
    
    elif n == 1:
        return [0, 1]

    res = [0, 1]
    target = 2
    power = 1
    count = 0

    for i in range(2, n+1):

        if count == target:
            count = 0
            target = 2 * target
            power += 1
            
        bin_ones = 1 + res[i - 2**power]
        res.append(bin_ones)
        count += 1

    return res

if __name__ == "__main__":

    n = 25

    print(f"Number of ones in binary representation from 1 to {n} = {countBits(n)}")