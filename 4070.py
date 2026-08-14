T = int(input())

for test_case in range(1, T + 1):
    N = int(input())

    dp = [1 for _ in range(N + 1)]

    for i in range(2, N + 1):
        dp[i] = dp[i - 1] + dp[i - 2] * 2

    print(f'#{test_case} {dp[N]}')