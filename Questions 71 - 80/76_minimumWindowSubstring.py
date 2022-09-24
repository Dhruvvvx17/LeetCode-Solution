from collections import Counter


def minWindow(s: str, t: str) -> str:

    if not s or not t or len(s) < len(t):
        return ""

    t_counter = Counter(t)
    chars = len(t_counter.keys())

    s_counter = Counter()
    matches = 0

    res = ""

    left, right = 0, -1

    while(left < len(s)):

        # EXTEND
        if matches < chars:

            # end of string reached and not enough matches yet
            if right == len(s)-1:
                return res

            # chars remaining in the string
            else:
                right += 1
                s_counter[s[right]] += 1

                if(t_counter[s[right]] > 0 and t_counter[s[right]] == s_counter[s[right]]):
                    matches += 1

        # CONTRACT
        else:
            s_counter[s[left]] -= 1
            if t_counter[s[left]] > 0 and s_counter[s[left]] == t_counter[s[left]]-1:
                matches -= 1
            left += 1

        if matches == chars:
            if not res:
                res = s[left: right+1]
            elif len(res) > right - left + 1:
                res = s[left: right+1]

    return res


if __name__ == "__main__":

    s = input("Enter s: ")
    t = input("Enter t: ")

    print(f"Minimum window substring is : {minWindow(s,t)}")
