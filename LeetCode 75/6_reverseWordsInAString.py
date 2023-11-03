def reverseWords(s: str) -> str:
    new_s = s.strip().split()[::-1]
    new_s = [x.strip() for x in new_s]
    return " ".join(new_s)

if __name__ == "__main__":
    s = "the sky is        blue                 "
    print(f"Reversed sentence: {reverseWords(s)}")