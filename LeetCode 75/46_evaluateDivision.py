from collections import defaultdict, deque

def calcEquation(equations, values, queries):

        adj = defaultdict(list)

        for i, eq in enumerate(equations):
            a,b = eq
            adj[a].append([b, values[i]])
            adj[b].append([a, 1/values[i]])

        def bfs(src, target):
            if src not in adj or target not in adj:
                return -1

            q, visit = deque(), set()
            q.append([src, 1])
            visit.add(src)

            while q:
                node, weight = q.popleft()
                if node == target:
                    return weight

                for neighbor, neighbor_weight in adj[node]:
                    if neighbor not in visit:
                        q.append([neighbor, weight * neighbor_weight])
                        visit.add(neighbor)

            return -1
            
        return [bfs(q[0], q[1]) for q in queries]

if __name__ == "__main__":
    equations = [["a","b"],["b","c"]]
    values = [2.0,3.0]
    queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]

    res = calcEquation(equations, values, queries)

    for r in res:
        print(r)
        