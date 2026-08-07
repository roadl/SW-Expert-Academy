#include <iostream>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool visited[8][8];
int arr[8][8];
int N, K;
int res;
bool flag;

void clear_visited() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
}

void dfs(int y, int x, int cnt) {
	if (cnt > res)
		res = cnt;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
			continue;

		if (arr[ny][nx] < arr[y][x]) {
			visited[ny][nx] = true;
			dfs(ny, nx, cnt + 1);
			visited[ny][nx] = false;
		}
		else if (flag && (arr[ny][nx] - K < arr[y][x])) {
			int tmp = arr[ny][nx];

			arr[ny][nx] = arr[y][x] - 1;
			flag = false;
			visited[ny][nx] = true;

			dfs(ny, nx, cnt + 1);

			arr[ny][nx] = tmp;
			flag = true;
			visited[ny][nx] = false;
		}
	}
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(0);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;

		int h_max = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				if (h_max < arr[i][j])
					h_max = arr[i][j];
			}
		}

		res = 0, flag = true;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == h_max) {
					clear_visited();
					visited[i][j] = true;
					dfs(i, j, 1);
				}
			}
		}

		cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}