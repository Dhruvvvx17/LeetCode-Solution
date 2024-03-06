def findCircleNum(grid):
        
        n = len(grid)
        visited = [0]*n

        '''
        Depth first search to find cliques
        '''
        def dfs(grid, j):
            visited[j] = res

            for k in range(n):
                if(j != k and grid[j][k] == 1 and not visited[k]):
                    dfs(grid, k)
            return


        res = 0
        for i in range(n):
            # found a new unvisited node
            if not visited[i]:
                visited[i] = res
                res += 1

                for j in range(n): 
                    if(i != j and grid[i][j] == 1 and not visited[j]):
                        dfs(grid, j)

        return res

if __name__ == "__main__":
    grid = [[1,0,0,1,0],[0,1,1,0,0],[0,1,1,0,0],[1,0,0,1,0],[0,0,0,0,1]]

    res = findCircleNum(grid)

    print(f"Number of provinces = {res}") 