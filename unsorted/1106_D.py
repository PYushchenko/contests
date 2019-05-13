import heapq

n, m = [int(i) for i in input().split()]

a = {i: set() for i in range(n)}

for i in range(m):
    u, v = [int(i) for i in input().split()]
    a[u - 1] |= {v - 1}
    a[v - 1] |= {u - 1}


def dfs(graph, start):
    visited, stack = set(), [start]
    heapq.heapify(stack)
    while stack:
        v = heapq.heappop(stack)
        if v not in visited:
            visited.add(v)
            print(v + 1)
            for k in graph[v] - visited:
                heapq.heappush(stack, k)
    return visited


dfs(a, 0)