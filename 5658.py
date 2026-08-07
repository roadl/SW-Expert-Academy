def get_idx(i, j, N):
    return int(j * N // 4 + i)

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N, K = input().split()
    N = int(N)
    K = int(K)
    
    s = input()
    
    s *= 2

    m = set()
    
    # 28
    # 0~6, 7~13, 14~20, 21~27
    # i = 0 ~ 6
    # j = 0 ~ 3
    # j * (N / 4) + i ~ (j + 1) * (N / 4) + i
    
    for i in range(N // 4):
        for j in range(4):
            m.add(s[get_idx(i, j, N):get_idx(i, j + 1, N)])
            
    print(f"#{test_case} {int(sorted(m, reverse=True)[K - 1], 16)}")
