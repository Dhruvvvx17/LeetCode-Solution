# The number of unique BSTs with n nodes is the catalan_number(n) 
# Using the binomial coefficient approach.
#
# Catalan(n) = (1/n+1)C(2n,n)
# # Takes O(n) time but repetetive operations in factorial

def factorial(n):
    fact = 1
    for i in range(2,n+1):
        fact *= i
    return fact

def Combination(n: int, r: int) -> int:
    return factorial(n)/(factorial(n-r)*factorial(r))
        
def numTrees(n: int) -> int:
    res = Combination(2*n,n)/(n+1)
    return int(res)
    
if __name__ == "__main__":
    n = int(input("Enter number of nodes: "))
    print(f"Number of BSTs with n unique nodes are: {numTrees(n)}")