def letterCombinations(digits):
    
    if len(digits) == 0:
        return []

    num_map = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }

    def dfs(index, path):
        if len(path) == len(digits):
            res.append("".join(path))
            return

        for digit in num_map[digits[index]]:
            dfs(index+1, path + [digit])

    index = 0
    res = []
    dfs(index, [])

    return res

if __name__ == "__main__":
    digits = "2354"

    print(f"Possible combinations: {letterCombinations(digits)}")