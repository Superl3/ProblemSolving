n = int(input())

walk_patterns = []

for i in range(n):
    walk_pattern = input()
    walk_patterns.append(walk_pattern)

for walk_pattern in walk_patterns:
    cnt = 0
    for walk in walk_pattern:
        if walk == 'D':
            break
        cnt += 1
    print(cnt)

