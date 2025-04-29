N, M = map(int, input().split(' '))

maps = {}
for i in range(M):
    u, v = map(int, input().split(' '))
    u -= 1
    v -= 1
    if u not in maps:
        maps[u] = []
    maps[u].append(v)
    
    if v not in maps:
        maps[v] = []
    maps[v].append(u)

visited = [False] * (N)

component_count = 0

queue = []
front = 0
for i in range(N):
    if visited[i]:
        continue

    if i in maps:
        queue.append(i)
        
    visited[i] = True
    component_count += 1

    while front < len(queue):
        cur = queue[front]
        front += 1

        for next in maps[cur]:
            if visited[next]:
                continue

            visited[next] = True
            queue.append(next)

print(component_count)