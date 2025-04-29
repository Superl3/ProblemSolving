n, m = map(int, input().split())

maps = []
dist = []

queue = []
for i in range(n):
    line = list(map(int, input().split()))
    maps.append(line)
    dist.append([-1]*m)

    for j, val in enumerate(line):
        if val == 2:
            queue.append((i,j))
            dist[i][j] = 0
        elif val == 0:
            dist[i][j] = 0

front = 0
while front < len(queue):
    cur_x, cur_y = queue[front]
    front += 1

    for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        next_x, next_y = cur_x + dx, cur_y + dy
        if next_x < 0 or next_x >= n or next_y < 0 or next_y >= m:
            continue

        if maps[next_x][next_y] != 1:
            continue 

        if dist[next_x][next_y] != -1:
            continue

        queue.append((next_x, next_y))
        dist[next_x][next_y] = dist[cur_x][cur_y] + 1

for line in dist:
    for item in line:
        print(item, end=' ')
    print()
