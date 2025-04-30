N = int(input())
for i in range(N):
    string = input()
    if string[-1] != '.':
        string += '.'
    
    print(string)