#include <iostream>

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
		int N;
		int trees[1001];
		int dp[1001];

		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> trees[i];

		dp[0] = 0;
		dp[1] = trees[1];

		for (int i = 2; i <= N; i++)
			dp[i] = dp[i - 2] + trees[i] > dp[i - 1] ? dp[i - 2] + trees[i] : dp[i - 1];

		cout << '#' << test_case << ' ' << dp[N] << '\n';
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}