#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int N, M, R, C, L;
int pipe_map[50][50];
int distance_map[50][50];

queue<pair<int, int>> q;

bool isTopOpen(int pipe) {
    return (pipe == 1 || pipe == 2 || pipe == 4 || pipe == 7);
}

bool isBottomOpen(int pipe) {
    return (pipe == 1 || pipe == 2 || pipe == 5 || pipe == 6);
}

bool isLeftOpen(int pipe) {
    return (pipe == 1 || pipe == 3 || pipe == 6 || pipe == 7);
}

bool isRightOpen(int pipe) {
    return (pipe == 1 || pipe == 3 || pipe == 4 || pipe == 5);
}

int getPipe(pair<int, int> p) {
    return pipe_map[p.first][p.second];
}

int getDistance(pair<int, int> p) {
    return distance_map[p.first][p.second];
}

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
bool (*from[])(int) = {isTopOpen, isBottomOpen, isRightOpen, isLeftOpen};
bool (*to[])(int)   = {isBottomOpen, isTopOpen, isLeftOpen, isRightOpen};

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M >> R >> C >> L;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> pipe_map[i][j];
                distance_map[i][j] = 2147483647;
            }
        }

        q.push(make_pair(R, C));
        distance_map[R][C] = 1;

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            int pipe = getPipe(cur);
            int distance = getDistance(cur);

            if (distance >= L)
                continue;

            for (int d = 0; d < 4; d++) {
                int ny = cur.first + dy[d];
                int nx = cur.second + dx[d];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (from[d](pipe) && to[d](pipe_map[ny][nx])
                    && distance_map[ny][nx] > distance + 1) {
                    distance_map[ny][nx] = distance + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (distance_map[i][j] <= L)
                    cnt++;

        printf("#%d %d\n", test_case, cnt);
    }
    return 0;
}