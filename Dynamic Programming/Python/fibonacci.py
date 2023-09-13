# given a number n, find the nth fibonacci number

# without memoization
def fib(n):
    if (n <= 2):
        return 1

    return fib(n-1) + fib(n-2)

cache = {}

# with memoization
def fib_memo(n):
    if (n in cache):
        return cache[n]
    
    if(n <= 2):
        return 1
    
    res = fib_memo(n-1) + fib_memo(n-2)
    cache[n] = res
    return cache[n]


if __name__ == "__main__":
    n = int(input("Enter n: "))

    # print(f"{n}th fibonacci number is: {fib(n)}")
    print(f"{n}th fibonacci number is: {fib_memo(n)}")
