from typing import List

def printVertically(s: str) -> List[str]:

    words = s.split(" ")

    max_len = max(map(len, words))

    for i in range(len(words)):
        words[i] += " " * (max_len - len(words[i]))

    res = []

    for i in range(max_len):
        vert_word = ""

        for word in words:

            if( i > len(word) and (not(vert_word) or vert_word[-1]==" ")):
                vert_word += " "

            else:
                vert_word += word[i]

        res.append(vert_word.rstrip())

    return res

if __name__ == "__main__":
    s = input("Enter N space separated words: ")

    print(f"Vertical words = {printVertically(s)}")
