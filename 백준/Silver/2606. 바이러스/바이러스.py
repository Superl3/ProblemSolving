computer_count = int(input())
connected_computer_count = int(input())

network = {}
for i in range(connected_computer_count):
    a, b = map(int, input().split())
    if a not in network:
        network[a] = set()
    if b not in network:
        network[b] = set()
    network[a].add(b)
    network[b].add(a)

visit = set({1})
if 1 in network:
    front = rear = 0
    queue= [1]
    while front < len(queue):
        cur = queue[front]
        front += 1
        for next in network[cur]:
            if next not in visit:
                visit.add(next)
                queue.append(next)
print(len(visit)-1)