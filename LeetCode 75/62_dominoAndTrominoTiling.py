def numTilings(n):
    
    mod = 10**9 + 7
    v = [0 for _ in range(1001)]

    v[1] = 1
    v[2] = 2
    v[3] = 5

    if n <= 3:
        return v[n]
    
    for i in range(4, n+1):
        v[i] = 2 * v[i-1] + v[i-3]
        v[i] %= mod
    
    return v[n]

if __name__ == "__main__":

    n = 15
    print(f"Number of tilings: {numTilings(15)}")