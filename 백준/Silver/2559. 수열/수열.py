N, K = map(int, input().split())
Arr = list(map(int, input().split()))

sum = 0
for i in range(K):
    sum += Arr[i]
max = sum

for i in range(K, N):
    sum += Arr[i] - Arr[i-K]
    if sum > max:
        max = sum

print(max)