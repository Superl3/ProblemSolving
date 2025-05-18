def next_abcd(nums):
    next_nums = []
    length = len(nums)
    for i in range(length):
        next_nums.append(abs(nums[(i+1)%length] - nums[i]))

    return next_nums

while True:
    a, b, c, d = map(int, input().split())
    if a == 0 and b == 0 and c == 0 and d == 0: break
    nums = [a,b,c,d]
    cnt = 0
    while True:
        loop_end = True
        digit = nums[0]
        for num in nums:
             if num != digit:
                 loop_end = False
                 break
        if loop_end: break
        nums = next_abcd(nums)
        cnt += 1
    print(cnt)