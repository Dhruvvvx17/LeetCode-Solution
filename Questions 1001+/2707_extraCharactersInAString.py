from typing import List

# TLE without the cache
def minExtraChar(s: str, dictionary: List[str]) -> int:
    
    words = set(dictionary)
    # stores the number of characters skipped upto index i
    cache = {len(s):0}

    # computes the minimum extra characters at index i
    def dfs(i):
        if i in cache:
            return cache[i]

        # branch-1: current char is skipped
        res = 1 + dfs(i+1)

        # branch-2: current char forms a word shift to next unvisited char
        for j in range(i, len(s)):
            if s[i:j+1] in words:
                res = min(res, dfs(j+1))
        
        cache[i] = res

        return res

    return dfs(0)

if __name__ == "__main__":
    s = input("Enter string: ")
    dictionary = ["leet", "code", "hello", "world"]

    print(f"Number of characters to skip: {minExtraChar(s, dictionary)}")