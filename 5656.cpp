#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int W, H;

vector<vector<int>> blocks;

int _max = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int N, int cnt);

void drop_block() {
    for (int x = 0; x < W; x++) {
        int write = H - 1;
        for (int y = H - 1; y >= 0; y--) {
            if (blocks[y][x] != 0) {
                blocks[write][x] = blocks[y][x];
                if (write != y) blocks[y][x] = 0;
                write--;
            }
        }
    }
}

void explode(int sy, int sx, int N, int cnt) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    q.push(make_pair(sy, sx));
    visited[sy][sx] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        int range = blocks[y][x];

        for (int i = 1; i < blocks[y][x]; i++) {
            for (int j = 0; j < 4; j++) {
                int ny = y + dy[j] * i;
                int nx = x + dx[j] * i;
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if (blocks[ny][nx] != 0 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }

        blocks[y][x] = 0;
        cnt++;
    }

    drop_block();

    dfs(N - 1, cnt);
}

void dfs(int N, int cnt) {
    if (cnt > _max)
        _max = cnt;

    if (N == 0)
        return;
    
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (blocks[j][i] != 0) {
                vector<vector<int>> backup = blocks;
                explode(j, i, N, cnt);
                blocks = backup;
                break;
            }
        }
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, total = 0;

        _max = 0;

        cin >> N >> W >> H;
        blocks.assign(H, vector<int>(W, 0));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> blocks[i][j];
                if (blocks[i][j] != 0)
                    total++;
            }
        }

        dfs(N, 0);

        printf("#%d %d\n", test_case, total - _max);
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}