import sys
M = int(input())

S= set()
for i in range(M):
    command = sys.stdin.readline().strip().split(' ')
    
    if command[0] == 'all':
        S={i for i in range(1,21)}
    elif command[0] == 'empty':
        S= set()
    else:
        command, number = command[0], int(command[1])
        if command == "add":
            if number not in S:
                S.add(number)
        elif command == "remove":
            if number in S:
                S.remove(number)
        elif command == "check":
            print(1 if number in S else 0)
        elif command == "toggle":
            if number in S:
                S.remove(number)
            else:
                S.add(number)
         