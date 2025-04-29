N = int(input())
arr = []
for i in range(N):
    line = list(map(int, input().split(' ')))
    arr.append(line)

def check_color(arr, x, y, size):
    color = arr[x][y]
    for i in range(x, x + size):
        for j in range(y, y +size):
            if arr[i][j] != color:
                return None
    return color

def divide(arr, x, y, size):
    result = [0, 0]
    color = check_color(arr, x, y, size)
    if color is not None:
        result[color] += 1
        return result
    else:
        size = size // 2
        for i in range(2):
            for j in range(2):
                sub_result = divide(arr, x + i * size, y + j*size, size)
                for k in range(2):
                    result[k] += sub_result[k]
        return result
    

result = divide(arr, 0, 0, N)
for color in result:
    print(color)