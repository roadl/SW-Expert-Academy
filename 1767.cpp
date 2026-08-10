#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[12][12];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int res, res_len;

vector<pair<int, int>> vec;

bool is_border(int y, int x) {
	return (y == 0 || y == N - 1 || x == 0 || x == N - 1);
}

int connect(int cur_y, int cur_x, int dy, int dx, int t) {
	int length = 0;

	while (!is_border(cur_y, cur_x)) {
		cur_y += dy;
		cur_x += dx;
		length++;

		arr[cur_y][cur_x] = t;
	}

	return length;
}

bool check(int cur_y, int cur_x, int dy, int dx) {
	while (!is_border(cur_y, cur_x)) {
		cur_y += dy;
		cur_x += dx;

		if (arr[cur_y][cur_x] != 0)
			return false;
	}

	if (arr[cur_y][cur_x] != 0)
		return false;

	return true;
}

void dfs(int p, int cnt, int length) {
	if (cnt > res) {
		res = cnt;
		res_len = length;
	}
	else if (cnt == res && length < res_len)
		res_len = length;

	if (p >= M)
		return;

	int cur_y = vec[p].first;
	int cur_x = vec[p].second;

	if (is_border(cur_y, cur_x)) {
		dfs(p + 1, cnt + 1, length);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (check(cur_y, cur_x, dy[i], dx[i])) {
			int len = connect(cur_y, cur_x, dy[i], dx[i], 2);
			dfs(p + 1, cnt + 1, length + len);
			connect(cur_y, cur_x, dy[i], dx[i], 0);
		}
	}

	dfs(p + 1, cnt, length);
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(0);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		vec.clear();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];

				if (arr[i][j] != 0)
					vec.push_back({ i, j });
			}
		}

		M = vec.size();
		res = 0;
		res_len = 0;

		dfs(0, 0, 0);

		cout << '#' << test_case << ' ' << res_len << '\n';
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}