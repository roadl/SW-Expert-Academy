#include <iostream>
#include <cmath>

using namespace std;

int N, X;
int map[20][20];
int res = 0;

void solve() {
	for (int y = 0; y < N; y++) {
		int cnt = 1;
		bool flag = false;

		for (int x = 1; x < N; x++) {
			if (flag)
				break;

			int prev = map[y][x - 1];
			int cur = map[y][x];

			if (abs(cur - prev) >= 2)
				flag = true;

			if (cur == prev)
				cnt++;
			else if (prev + 1 == cur) {
				if (cnt >= X)
					cnt = 1;
				else
					flag = true;
			}
			else if (prev - 1 == cur) {
				for (int i = 0; i < X; i++, x++) {
					if (x >= N || cur != map[y][x]) {
						flag = true;
						break;
					}
				}
				x--;
				cnt = 0;
			}
		}

		if (!flag)
			res++;
	}

	for (int x = 0; x < N; x++) {
		int cnt = 1;
		bool flag = false;

		for (int y = 1; y < N; y++) {
			if (flag)
				break;

			int prev = map[y - 1][x];
			int cur = map[y][x];

			if (abs(cur - prev) >= 2)
				flag = true;

			if (cur == prev)
				cnt++;
			else if (prev + 1 == cur) {
				if (cnt >= X)
					cnt = 1;
				else
					flag = true;
			}
			else if (prev - 1 == cur) {
				for (int i = 0; i < X; i++, y++) {
					if (y >= N || cur != map[y][x]) {
						flag = true;
						break;
					}
				}
				y--;
				cnt = 0;
			}
		}

		if (!flag)
			res++;
	}
}

int main(int argc, char **argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> X;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		res = 0;

		solve();

		cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}