#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

vector<string> arr;
int dis[100][100];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main(int argc, char **argv)
{
    int test_case;
    int t;

    cin >> t;

    for (test_case = 1; test_case <= t; ++test_case)
    {
        queue<pair<int, int>> q;
        int n;
        int res = 0;

        cin >> n;

		arr.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];

			for (int j = 0; j < n; j++) {
				dis[i][j] = -1;

				if (arr[i][j] == '2') {
					q.push({ i, j });
					dis[i][j] = 0;
				}
			}
        }

        while(!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= n)
					continue;

                if (arr[ny][nx] == '0' && dis[ny][nx] == -1) {
                    q.push({ny, nx});
                    dis[ny][nx] = dis[y][x] + 1;
                }
                else if (arr[ny][nx] == '3') {
					res = dis[y][x];
                    break;
                }
            }

            if (res != 0)
                break;
        }

        cout << '#' << test_case << ' ' << res << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}