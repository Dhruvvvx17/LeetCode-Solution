def minReorder(n, connections):
    
    adj_list = {city: [] for city in range(n)}
    for a,b in connections:
        adj_list[a].append((b,1))        
        adj_list[b].append((a,0))

    q = []
    visited = set()
    res = 0

    q.append(0)        
    visited.add(0)

    while(len(q) > 0):
        curr = q.pop(0)

        for city, edge_direction in adj_list[curr]:
            if city not in visited:
                res += edge_direction
                q.append(city)
                visited.add(city)

    return res

if __name__ == "__main__":
    n = 6
    connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]

    res = minReorder(n, connections)

    print(f"Minimum connections to be modified = {res}")
    