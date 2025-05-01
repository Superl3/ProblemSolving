while True:
    N, D = map(int, input().split())
    if N == 0 and D == 0:
        break

    attendance = [True] * N
    for d in range(D):
        dinner = list(map(int, input().split()))
        for i in range(len(dinner)):
            if dinner[i] == 0:
                attendance[i] = False
    
    yes = False
    for a in attendance:
        if a:
            print("yes")
            yes = True
            break

    if not yes:
        print("no")