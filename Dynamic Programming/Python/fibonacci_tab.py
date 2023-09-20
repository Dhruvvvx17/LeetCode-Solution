# Given an integer n, find the nth fibonacci number using tabulation method
# Time complexity: O(n)
# Space complexity: O(n)

def fib_tab(n):

    table = [0] * (n+1)

    table[1] = 1

    for i in range(2, n+1):
        table[i] = table[i-1] + table[i-2]

    return table[n]

if __name__ == "__main__":
    n = int(input("Enter n: "))

    print(f"{n}th fibonacci number is: {fib_tab(n)}")
