#include <iostream>

using namespace std;

unsigned long long dp[26];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;

        cin >> N;

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= N; i++)
            dp[i] = dp[i - 1] + dp[i - 2] * 2;

        cout << '#' << test_case << ' ' << dp[N] << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}