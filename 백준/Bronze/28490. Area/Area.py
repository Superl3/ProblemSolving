n = int(input())

max = 0
for i in range(n):
    h, w = map(int, input().split(' '))
    if h * w > max:
        max = h * w

print(max)