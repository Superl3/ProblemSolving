import sys
input = sys.stdin.readline  # input을 sys.stdin.readline으로 대체

def reverse_and_make_list(raw):
    reverse = [int(s[::-1]) for s in raw]
    return reverse

raw = input().split()
N = int(raw[0])

numbers = reverse_and_make_list(raw[1:])
while True:
    if len(numbers) >= N:
        break

    numbers += reverse_and_make_list(input().split())

numbers.sort()
for number in numbers:
    sys.stdout.write(str(number) + '\n')