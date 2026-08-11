#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		int dp[1001];
		int V[100], C[100];

		cin >> N >> K;

		for (int i = 0; i <= K; i++)
			dp[i] = 0;

		for (int i = 0; i < N; i++) {
			cin >> V[i] >> C[i];

			for (int j = K; j >= V[i]; j--) {
				if (dp[j - V[i]] + C[i] > dp[j])
					dp[j] = dp[j - V[i]] + C[i];
			}
		}

		cout << '#' << test_case << ' ' << dp[K] << '\n';
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}