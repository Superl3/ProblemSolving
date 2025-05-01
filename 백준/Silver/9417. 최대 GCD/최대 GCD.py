from itertools import combinations

def findGCD(a, b):
    while b != 0:
        a, b = b, a % b
    return a

T = int(input())
for t in range(T):
    nums = list(map(int, input().split()))
    pairs = list(combinations(nums, 2))

    max = 0
    for pair in pairs:
        gcd = findGCD(pair[0], pair[1])
        if gcd > max:
            max = gcd
            
    print(max)