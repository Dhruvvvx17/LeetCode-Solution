# encryption validity

# given:
# instructionCount = 1000
# validityPeriod = 10000
# n = 4
# keys = [2,4,8,2]

# find the max divisor:
# 2: divisors -> [2, 2] -> 2
# 4: divisors -> [2, 4, 2] -> 3
# 8: divisors -> [2, 4, 8, 2] -> 4  (max divisor count)
# 2: divisors -> [2, 2] -> 2

# encryption strength = 4 * 10^5
# hacker_tests = instructionCount * validityPeriod
#                         = 1000 * 10000 = 10^7

# as encryption strength is less than hacker_tests, output is [0, encryption strength] else it would be [1, encryption strength]

def encryptionValidity(instructionCount, validityPeriod, keys):

    hijacker_tests = instructionCount * validityPeriod

    degree_map = {}
    max_deg = -1
    max_val = -1

    for key in keys:

        if key not in degree_map:
            key_degree = 0

            for div in keys:
                if(key % div == 0):
                    key_degree += 1

            degree_map[key] = key_degree

            if key_degree > max_deg:
                max_deg = key_degree
                max_val = key

    strength = max_deg * (10**5)

    if(strength < hijacker_tests):
        return [1, strength]
    else:
        return [0, strength]
            