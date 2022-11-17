def isInterleave(s1: str, s2: str, s3: str) -> bool:

    if(len(s1) + len(s2) != len(s3)):
        return False

    # dp cache that stores (index1, index2) as key and T/F as value
    dp = {}
    return dfs(0, s1, 0, s2, s3, dp)


def dfs(i, s1, j, s2, s3, dp):

    if(i == len(s1) and j == len(s2) and i+j == len(s3)):
        return True

    if((i, j) in dp):
        return dp[(i, j)]

    if(i < len(s1) and s1[i] == s3[i+j] and dfs(i+1, s1, j, s2, s3, dp)):
        return True

    if(j < len(s2) and s2[j] == s3[i+j] and dfs(i, s1, j+1, s2, s3, dp)):
        return True

    dp[(i, j)] = False

    return False


if __name__ == "__main__":

    s1 = input("Enter string 1: ")
    s2 = input("Enter string 2: ")
    s3 = input("Enter string 3: ")

    if(isInterleave(s1, s2, s3)):
        print("Interleaving strings!")
    else:
        print("Not Interleaving strings")
