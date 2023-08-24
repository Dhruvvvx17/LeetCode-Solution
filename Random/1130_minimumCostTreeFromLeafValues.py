def mctFromLeafValues(arr):
    res = 0
    A = arr
    while len(A) > 1:
        i = A.index(min(A))
        res += min(A[i - 1:i] + A[i + 1:i + 2]) * A.pop(i)
    return res


if __name__ == "__main__":
    arr = [2, 4, 6]

    print(f"Minimum cost Tree: ", mctFromLeafValues(arr))
