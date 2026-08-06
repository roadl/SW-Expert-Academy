from collections import deque
T = int(input())

for test_case in range(1, T + 1):
 
    n = int(input())
    graph = []
 
    for _ in range(n):
        stores = input()
        graph.append([int(item) for item in stores])
 
    visited = [[False for _ in range(n)] for _ in range(n)]
    distance = [[0 for _ in range(n)] for _ in range(n)]
 
    queue = deque()
 
    dx = [-1, 1, 0, 0]
    dy = [0, 0, 1, -1]
 
    start_x, start_y = 0, 0
    end_x, end_y = 0, 0
 
    for i in range(len(graph)):
        for j in range(len(graph[i])):
            if graph[i][j] == 2:
                start_x, start_y = i, j
 
            elif graph[i][j] == 3:
                end_x, end_y = i, j
 
    queue.append((start_x, start_y))
    visited[start_x][start_y] = True
    distance[start_x][start_y] = 0
 
    while queue:
 
        x, y = queue.popleft()
 
        if graph[x][y] == 3:
            distance[x][y] -= 1
            break
 
        for ax, ay in zip(dx, dy):
            nx = x + ax
            ny = y + ay
            if nx < n and nx >= 0 and ny < n and ny >= 0:
                if graph[nx][ny] != 1 and not visited[nx][ny]:
                    distance[nx][ny] = distance[x][y] + 1
                    visited[nx][ny] = True
                    queue.append((nx, ny))
 
 
    print(f"#{test_case} {distance[end_x][end_y]}")
 