def dailyTemperatures(temperatures):
    
    n = len(temperatures)
    res = [0] * n
    stack = []  # the stack keeps the index of what is yet to find a greater temperature

    for i in range(n):

        while len(stack) and temperatures[i] > temperatures[stack[-1]]:
            index = stack[-1]
            stack.pop(-1)
            res[index] = i - index
        
        stack.append(i)
    
    return res

if __name__ == "__main__":

    temperatures = [73,74,75,71,69,72,76,73]
    print(f"Daily Temperatures: {dailyTemperatures(temperatures)}")