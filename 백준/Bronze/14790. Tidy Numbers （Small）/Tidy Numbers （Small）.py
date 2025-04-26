def solve(N: int)->str:
    
    last_tidy_number = None
    while last_tidy_number is None:
        str_N = str(N)

        is_tidy = True
        prev_digit = None
        for digit in str_N:
            if prev_digit is not None and prev_digit > digit:
                is_tidy = False
                break

            prev_digit = digit

        if is_tidy:
            last_tidy_number = str_N

        N-=1

    return last_tidy_number
        

T = int(input())
for t in range(1,T+1):
    N = int(input())
    print(f"Case #{t}: {solve(N)}")