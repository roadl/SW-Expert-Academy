#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);

    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;

        vector<int> vec;
        
        cin >> N;

        vec.resize(N);

        for (int i = 0; i < N; i++)
            cin >> vec[i];

        int f = 0, b = N - 1, _max = (b - f) * (vec[f] + vec[b]);

        while (f <= b) {
            int n = b - f;
            int front_v = (n - 1) * vec[f + 1] - n * vec[f] - vec[b];
            int back_v = -vec[f] - n * vec[b] + (n - 1) * vec[b - 1];

            if (front_v > back_v)
                f++;
            else
                b--;

            int val = (b - f) * (vec[f] + vec[b]);

            if (val > _max)
                _max = val;
        }

        cout << '#' << test_case << ' ' << _max << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}