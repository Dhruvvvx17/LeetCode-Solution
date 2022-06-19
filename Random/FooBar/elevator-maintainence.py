def compare(x, y):
    res = True
    x_list = list(x.split('.'))
    y_list = list(y.split('.'))
    flag = 0

    shorter = []

    if len(x_list) < len(y_list):
        diff = len(y_list) - len(x_list)
        zeros = ['0']*diff
        x_list += zeros
        shorter = 1

    if len(y_list) < len(x_list):
        diff = len(x_list) - len(y_list)
        zeros = ['0']*diff
        y_list += zeros
        shorter = 2

    for i in range(len(x_list)):
        if(int(x_list[i]) < int(y_list[i])):
            res = True
            flag = 1
            break
        elif(int(x_list[i]) > int(y_list[i])):
            res = False
            flag = 1
            break

    if(flag):
        return res

    else:
        if shorter == 1:
            return True
        else:
            return False


def merge(versions, L, R):
    l_size = len(L)
    r_size = len(R)

    i = j = k = 0

    while(i < l_size and j < r_size):
        if(compare(L[i], R[j])):
            versions[k] = L[i]
            i += 1
        else:
            versions[k] = R[j]
            j += 1
        k += 1

    # copy all left over elements in L if R is exhausted
    while(i < l_size):
        versions[k] = L[i]
        i += 1
        k += 1

    # copy all left over elements in R if L is exhausted
    while(j < r_size):
        versions[k] = R[j]
        j += 1
        k += 1


def mergeSortVersions(versions):

    if(len(versions) == 1):
        return

    m = len(versions)//2

    L = versions[:m]

    R = versions[m:]

    mergeSortVersions(L)
    mergeSortVersions(R)
    merge(versions, L, R)

    return versions


def solution(versions):
    res = mergeSortVersions(versions)
    return res


# versions = [5, 4, 3, 2, 1]
versions1 = ["1.11", "2", "1.2", "2.0.0", "0.1", "1.2.1", "1.1.1", "2.0"]


versions2 = ["1.11", "2.0.0", "1.2", "2", "0.1", "1.2.1", "1.1.1", "2.0"]
solution(versions2)


versions3 = ["1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"]
solution(versions3)


print("Versions 1: ", solution(versions1))
print("Versions 2: ", versions2)
print("Versions 3: ", versions3)
