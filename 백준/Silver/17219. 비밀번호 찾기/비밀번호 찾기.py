N, M = map(int, input().split())

IDPW = {}

for i in range(N):
    ID, PW = input().split()
    IDPW[ID] = PW

for j in range(M):
    ID = input()
    print(IDPW[ID])