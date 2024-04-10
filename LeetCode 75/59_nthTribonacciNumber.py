def tribonacci(n):
    a, b, c = 0, 1, 1

    if n == 0:
        return 0

    if n == 1 or n == 2:
        return 1

    for i in range(3, n+1):
        temp = a + b + c
        a = b
        b = c
        c = temp
    
    return c

if __name__ == "__main__":
    n = 25
    print(f"{n}th tribonacci number: {tribonacci(n)}")