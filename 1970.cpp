#include <iostream>

using namespace std;

int arr[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
int res[8];

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

		cin >> N;

		for (int i = 0; i < 8; i++) {
			res[i] = 0;
			
			while (N >= arr[i]) {
				res[i]++;
				N -= arr[i];
			}
		}
        
		cout << '#' << test_case << '\n';
		for (int i = 0; i < 7; i++)
			cout << res[i] << ' ';
		cout << res[7] << '\n';
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}