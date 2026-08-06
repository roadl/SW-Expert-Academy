#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> vec;

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;

        cin >> N;

        vec.resize(N);

        for (int i = 0; i < N; i++)
            cin >> vec[i];

        cout << '#' << test_case;

        for (int i = 0; i < N; i++) {
            if (i % 2 == 0)
                cout << ' ' << vec[i / 2];
            else
                cout << ' ' << vec[(i / 2) + (N + 1) / 2];
        }
        cout << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}