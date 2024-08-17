# The solution is simply a fibonacci series

def climbStairs(n: int) -> int:
    
    step_1 = 1
    step_2 = 1

    while(n):
        step_1, step_2 = step_1 + step_2, step_1
        n -= 1

    return step_2

if __name__ == "__main__":
    n = int(input("Enter n: "))
    print(f"Number of ways to climb stairs = {climbStairs(n)}")