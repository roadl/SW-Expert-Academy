#include <iostream>

using namespace std;

int D, W, K;
int arr[13][20];

int flag[13];

int res;

bool check() {
	int cnt;

	if (K == 1)
		return true;

	for (int x = 0; x < W; x++) {
		cnt = 1;
		for (int y = 1; y < D; y++) {
			int prev = flag[y - 1] == -1 ? arr[y - 1][x] : flag[y - 1];
			int cur = flag[y] == -1 ? arr[y][x] : flag[y];

			if (prev == cur)
				cnt++;
			else
				cnt = 1;

			if (cnt >= K)
				break;

			if (y == D - 1)
				return false;
		}
	}

	return true;
}

void recur(int cnt, int i) {
	if (cnt == K || i == D) {
		if (cnt < res && check())
			res = cnt;
		return;
	}

	// i번째 약품 안 칠함
	recur(cnt, i + 1);

	// i번째 A로 칠함
	flag[i] = 0;
	recur(cnt + 1, i + 1);
	flag[i] = -1;

	// i번째 B로 칠함
	flag[i] = 1;
	recur(cnt + 1, i + 1);
	flag[i] = -1;
}

int main(int argc, char **argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> D >> W >> K;

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> arr[i][j];
			}
			flag[i] = -1;
		}

		res = K;

		recur(0, 0);

		cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}