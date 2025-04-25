letter = input()

teams = ["MatKor", "WiCys", "CyKor", "AlKor", "$clear"]
for team in teams:
    if letter == team[0]:
        print(team)
        break
