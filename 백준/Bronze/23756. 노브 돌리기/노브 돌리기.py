def find_best(original, target):
    ccw = (original+360-target)%360
    cw = (target+360-original)%360
    if ccw < cw:
        return ccw
    else:
        return cw

min = 0
N = int(input())
prev = int(input())
for i in range(N):
    cur = int(input())
    min += find_best(prev, cur)

    prev = cur

print(min)