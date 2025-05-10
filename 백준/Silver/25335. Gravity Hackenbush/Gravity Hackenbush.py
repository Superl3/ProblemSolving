N, M = map(int, input().split())
for i in range(N):
    input()
color_count = [0,0,0]
for j in range(M):
    color = input().split()[-1]
    if color == "R":
        color_count[0] += 1
    elif color == "B":
        color_count[1] += 1
    elif color == "G":
        color_count[2] += 1

color_count[2] %= 2
min_color = min(color_count[0], color_count[1])
color_count[0] -= min_color
color_count[1] -= min_color

turn = color_count[2]

while True:
    if color_count[turn%2] < 1:
        break

    color_count[turn%2] -= 1
    turn += 1

if turn%2 == 0:
    print("jhnan917")
else:
    print("jhnah917")