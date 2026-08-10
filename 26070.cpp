#include <iostream>
#include <vector>

using namespace std;

// 0 오른쪽 1 아래 2 왼쪽 3 위
int N, M;
int dir, cur_x, cur_y;
int res;
vector<pair<int, int>> vec;

int check(int des_y, int des_x) {
	if (dir == 0) {
		if (des_y == cur_y && des_x >= cur_x)
			return 0;
		else if (des_y > cur_y && des_x >= cur_x)
			return 1;
		else if (des_y > cur_y && des_x < cur_x)
			return 2;
		else
			return 3;
	}
	else if (dir == 1) {
		if (des_y >= cur_y && des_x == cur_x)
			return 0;
		else if (des_y >= cur_y && des_x < cur_x)
			return 1;
		else if (des_y < cur_y && des_x < cur_x)
			return 2;
		else
			return 3;
	}
	else if (dir == 2) {
		if (des_y == cur_y && des_x <= cur_x)
			return 0;
		else if (des_y < cur_y && des_x <= cur_x)
			return 1;
		else if (des_y < cur_y && des_x > cur_x)
			return 2;
		else
			return 3;
	}
	else if (dir == 3) {
		if (des_y <= cur_y && des_x == cur_x)
			return 0;
		else if (des_y <= cur_y && des_x > cur_x)
			return 1;
		else if (des_y > cur_y && des_x > cur_x)
			return 2;
		else
			return 3;
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
		cin >> N;

		M = 0;
		dir = 0;
		cur_x = 0, cur_y = 0;
		res = 0;

		vec.clear();
		vec.resize(10);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int t;
				cin >> t;

				if (t != 0) {
					vec[t] = { i, j };
					M++;
				}
			}
		}

		for (int i = 1; i <= M; i++) {
			int rotate_cnt = check(vec[i].first, vec[i].second);

			dir += rotate_cnt;
			dir %= 4;
			cur_y = vec[i].first, cur_x = vec[i].second;

			res += rotate_cnt;
		}

		cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}