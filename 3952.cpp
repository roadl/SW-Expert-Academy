#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int N, M;
		cin >> N >> M;

		vector<vector<int>> m(N + 1);
		vector<int> vec(N + 1, 0);

		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;

			m[a].push_back(b);
			vec[b]++;
		}

		queue<int> q;

		for (int student = 1; student <= N; ++student) {
			if (vec[student] == 0) {
				q.push(student);
			}
		}

		cout << '#' << test_case;

		while (!q.empty()) {
			int current = q.front();
			q.pop();

			cout << ' ' << current;

			for (int next : m[current]) {
				vec[next]--;

				if (vec[next] == 0) {
					q.push(next);
				}
			}
		}

		cout << '\n';
	}

	return 0;
}
