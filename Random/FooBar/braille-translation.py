def solution(s):
    # Your code here
    translation = {
        "a": "100000", "n": "101110",
        "b": "110000", "o": "101010",
        "c": "100100", "p": "111100",
        "d": "100110", "q": "111110",
        "e": "100010", "r": "111010",
        "f": "110100", "s": "011100",
        "g": "110110", "t": "011110",
        "h": "110010", "u": "101001",
        "i": "010100", "v": "111001",
        "j": "010110", "w": "010111",
        "k": "101000", "x": "101101",
        "l": "111000", "y": "101111",
        "m": "101100", "z": "101011",
        " ": "000000", "!": "000001"
    }

    res = ""
    for letter in s:
        if letter.isupper():
            res += translation["!"]
            letter = letter.lower()

        res += translation[letter]

    return res


print(solution("The quick brown fox jumps over the lazy dog"))
