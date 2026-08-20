#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, t, oper;

		priority_queue<int> q;

		cin >> N;

		cout << '#' << test_case;

		for (int i = 0; i < N; i++) {
			cin >> oper;

			if (oper == 1) {
				cin >> t;
				q.push(t);
			}
			else {
				if (q.empty())
					cout << ' ' << -1;
				else {
					cout << ' ' << q.top();
					q.pop();
				}
			}
		}

		cout << '\n';
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}