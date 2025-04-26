alarm_time = input().strip()

pos = {"0":(1,0), "1":(0,3), "2":(1,3), "3":(2,3), "4":(0,2), 
        "5":(1,2), "6":(2,2), "7":(0,1), "8":(1,1), "9":(2,1)}

def calc_effort(a, b):
    return abs(pos[a][0] - pos[b][0]) + abs(pos[a][1] - pos[b][1])


def avail_list(original, gap="24"):
    avails = []
    x = 0
    while original + x * gap < 100:
        avails.append(original + x * gap)
        x += 1
    
    return avails


avail_hh = avail_list(int(alarm_time[:2]), 24)
avail_mm = avail_list(int(alarm_time[-2:]), 60)

min_effort = None
min_time = None

for hh in avail_hh:
    for mm in avail_mm:

        effort = 0
        str_time = str(hh).zfill(2) + str(mm).zfill(2)
        for i in range(len(str_time)-1):
            effort += calc_effort(str_time[i], str_time[i+1])

        if min_effort is None or min_effort > effort:
            min_effort = effort
            min_time = str_time[:2] + ":" + str_time[-2:]

print (min_time)