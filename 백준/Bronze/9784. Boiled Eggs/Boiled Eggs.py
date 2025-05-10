T = int(input())
for t in range(T):
    n, P, Q = map(int, input().split())
    eggs = list(map(int, input().split()))
    eggs.sort()

    egg_count = 0
    egg_sum = 0
    for egg in eggs:
        if egg_count+1 > P or egg_sum + egg > Q:
            break

        egg_count += 1
        egg_sum += egg
    
    print(f"Case {t+1}: {egg_count}")