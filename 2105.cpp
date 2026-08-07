#include <iostream>

using namespace std;

int N;
int arr[20][20];

int flag[101];

int dy[4] = { 1, 1, -1, -1 };
int dx[4] = { -1, 1, 1, -1 };

int res;

// dir 0 왼아래, 1 오아래, 2 오위, 3 왼위
void recur(int y, int x, int dir, int l_cnt, int r_cnt, int cnt) {
	if (l_cnt == 0 && r_cnt == 0) {
		if (cnt > res)
			res = cnt;
		return;
	}

	if (y < 0 || y >= N || x < 0 || x >= N || flag[arr[y][x]] == true)
		return;

	flag[arr[y][x]] = true;

	if (dir == 0) {
		recur(y + dy[dir], x + dx[dir], dir, l_cnt + 1, r_cnt, cnt + 1);

		dir = 1;
		recur(y + dy[dir], x + dx[dir], dir, l_cnt, r_cnt + 1, cnt + 1);
	}
	else if (dir == 1) {
		recur(y + dy[dir], x + dx[dir], dir, l_cnt, r_cnt + 1, cnt + 1);

		dir = 2;
		recur(y + dy[dir], x + dx[dir], dir, l_cnt - 1, r_cnt, cnt + 1);
	}
	else if (dir == 2) {
		if (l_cnt == 0) {
			dir = 3;
			recur(y + dy[dir], x + dx[dir], dir, l_cnt, r_cnt - 1, cnt + 1);
		}
		else {
			recur(y + dy[dir], x + dx[dir], dir, l_cnt - 1, r_cnt, cnt + 1);
		}
	}
	else if (dir == 3) {
		recur(y + dy[dir], x + dx[dir], dir, l_cnt, r_cnt - 1, cnt + 1);
	}


	flag[arr[y][x]] = false;
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];

		for (int i = 0; i < 100; i++)
			flag[i] = false;

		res = -1;

		for (int i = 0; i < N - 1; i++) {
			for (int j = 1; j < N - 1; j++) {
				flag[arr[i][j]] = true;
				recur(i + dy[0], j + dx[0], 0, 1, 0, 1);
				flag[arr[i][j]] = false;
			}
		}

		cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}