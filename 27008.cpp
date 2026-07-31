#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, t;

        vector<pair<int, int>> vec;
        vector<pair<int, int>> back;
        
        cin >> N;

        vec.resize(N);

        for (int i = 0; i < N; i++) {
            cin >> t;

            vec[i] = make_pair(i, t);
        }

        int _max = 0;

        for (int i = N - 1; i > 0; i--) {
            if (vec[i].second > _max) {
                _max = vec[i].second;
                back.push_back(vec[i]);
            }
        }

        _max = 0;

        for (int i = 0; i < N - 1; i++) {
            for (int j = back.size() - 1; j >= 0; j--) {
                if (i >= back[j].first)
                    break;
                
                int value = (back[j].first - i) * (vec[i].second + back[j].second);

                if (value > _max)
                    _max = value;
            }
        }

        printf("#%d %d\n", test_case, _max);
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}