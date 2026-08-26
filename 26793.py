T = int(input())

for test_case in range(1, T + 1):
    N = int(input())

    sum = 0
    res = 10000000000

    tasks = []

    for _ in range(N):
        d, t = input().split()

        d = int(d)
        t = int(t)

        tasks.append((t, d))

    tasks.sort()

    for t, d in tasks:
        sum += d
        res = min(res, t - sum)

    print(res)