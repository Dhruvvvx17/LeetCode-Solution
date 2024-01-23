def asteroidCollision(ast):
    
    if len(ast) == 0 or len(ast) == 1:
        return ast

    stack = []

    for a in ast:

        # empty stack
        if(len(stack) == 0):
            stack.append(a)

        # stack top going left -> no collision
        elif(stack[-1] < 0):
            stack.append(a)

        # stack top going right -> possible collision
        else:
            # current asteroid going left
            if(a < 0):
                destroyed = False
                while( len(stack) > 0 and stack[-1] > 0 and not destroyed):
                    if(stack[-1] > -a):
                        destroyed = True
                    elif(stack[-1] == -a):
                        destroyed = True
                        stack.pop()
                    else:
                        stack.pop()

                if not destroyed:
                    stack.append(a)

            # current asteroid going right -> no collision
            else:
                stack.append(a)

    return stack

if __name__ == "__main__":

    ast = [10,-2,4,8,-5,9,-12,5]

    print(f"Final asteroids standing: {asteroidCollision(ast)}")
    