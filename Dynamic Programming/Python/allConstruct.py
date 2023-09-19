# Given a target string and a list of strings called wordBank, return the number of ways to construct the target string.
# using the wordBank. A word in the wordbank can be used multiple times.
# The trick is to return [[]] when creating "" and [] when failing to create a word.
# Time complexity = polynomial as all combinations have to be generated

cache = {}

def allConstruct(target, wordBank):

    if(target == ""):
        return [[]]
    
    if(target in cache):
        return cache[target]
    
    allWays = []

    for word in wordBank:

        if(target[:len(word)] == word):
            remainingWord = target[len(word):]
            currWays = allConstruct(remainingWord, wordBank)
            for ways in currWays:
                t = [word] + ways
                allWays.append(t)

    cache[target] = allWays
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

    res = allConstruct(target, wordBank)

    if(res):
        print(f"{target} can be constructed from the wordbank in {len(res)} ways")
        for item in res:
            print(item)
    else:
        print(f"{target} cannot be constructed from the wordbank")