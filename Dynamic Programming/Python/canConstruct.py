# Given a target string and a list of strings called wordBank, return True if target string can be created using combinations
# of strings from the wordBank. A word in the wordbank can be used multiple times.
# Brute force time complexity: O((n^m) * m) = O((branching factor ^ height) * string copying at remainingWord)
# Memoized time complexity: O(n * m * m) = O(unique recursive calls * string copying at remainingWord)
# Space complexity for both: O(m * m) = O(cache size at max * suffix string at every call)

cache = {}

def canConstruct(target, wordBank):
    if(target == ""):
        return True
    
    if(target in cache):
        return cache[target]

    for word in wordBank:
        if target[0:len(word)] == word:
            remainingWord = target[len(word):]
            if(canConstruct(remainingWord, wordBank)):
                cache[target] = True
                return cache[target]
            
    cache[target] = False
    return cache[target]

if __name__ == "__main__":
    target = input("Enter target string: ")

    n = int(input("Enter no. of words in wordbank: "))
    wordBank = []
    i = 0
    while(i < n):
        temp = input(f"Enter word {i}: ")
        wordBank.append(temp)
        i += 1

    if(canConstruct(target, wordBank)):
        print(f"{target} can be constructed from the wordbank")
    else:
        print(f"{target} cannot be constructed from the wordbank")