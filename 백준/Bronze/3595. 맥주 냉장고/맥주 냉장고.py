import math

n = int(input())

min_area = -1
min_area_combination = []

for a in range(1, int(n**(1/3))+2):
    if n % a != 0:
        continue
    
    for b in range(1, int((n/a)**(1/2))+2):
        if (n/a) % b != 0:
            continue

        c = n // (a * b)

        area = 2 * (a*b + b*c + c*a)
        if min_area == -1 or area < min_area:
            min_area = area
            min_area_combination = [a, b, c]

for comb in min_area_combination:
    print(comb, end=' ')