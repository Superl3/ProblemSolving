n = int(input())

cnt = 0
number = 0

while number < n:
    number += 1
    cnt += 1

    if number == n: break
    
    idx = fifty_cnt = 0
    str_number = str(number)
    while idx < len(str_number):
        if str_number[idx] == '5' and idx+1 < len(str_number) and str_number[idx+1] == '0':
            fifty_cnt += 1
            break
        idx += 1
    cnt += fifty_cnt

print(cnt)