N, r, c = map(int, input().split(' '))

cnt = 0

Z = [(0,0), (1, 0), (-1, 1), (1, 0)]

# def traverse(x, y, size):
#     global cnt
#     if size == 1:
#         for z in Z:
#             x += z[0]
#             y += z[1]
#             if r == y and c == x:
#                 return True
            
#             cnt += 1
#     else:
#         next_width = 2**(size-1)
#         for z in Z:
#             x += z[0]*next_width
#             y += z[1]*next_width
#             if traverse(x, y, size-1):
#                 return True
#     return False

def traverse(x, y, size):
    global cnt
    if size == 1:
        for z in Z:
            x += z[0]
            y += z[1]
            if r == y and c == x:
                return True
            
            cnt += 1
    else:
        next_width = 2**(size-1)
        for z in Z:
            x += z[0]*next_width
            y += z[1]*next_width
            if (y <= r and r <= y+next_width) and (x <= c and c <= x+next_width):
                if traverse(x, y, size-1):
                    return True
            else:
                cnt += next_width ** 2
    return False

traverse(0, 0, N)
print(cnt)