

def characterReplacement(s: str, k: int) -> int:

    l = 0
    res = 0
    freq = {}

    for r in range(len(s)):
        if s[r] not in freq:
            freq[s[r]] = 1
        else:
            freq[s[r]] += 1

        while((r - l + 1) - max(freq.values())) > k:
            freq[s[l]] -= 1
            l += 1

        res = max(res, r-l+1)

    return res


if __name__ == "__main__":

    s = "aabcdaabbacbfbgrdaaecsa"
    k = 3

    print(
        f"Longest string with {k} character replacements: {characterReplacement(s,k)}")
