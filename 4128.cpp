#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr[16][16];
int min_diff = 2147483647;
bool flag[16];

int cal_diff() {
    int s1 = 0, s2 = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (flag[i] == flag[j]) {
                if (flag[i] == true)
                    s1 += arr[i][j];
                else
                    s2 += arr[i][j];
            }
        }
    }

    return abs(s1 - s2);
}

void recur(int cnt, int i) {
    if (i + cnt > N)
        return;

    if (cnt == 0) {
        int diff = cal_diff();
        if (diff < min_diff)
            min_diff = diff;
        return;
    }

    // i번재 재료 미선택
    flag[i] = false;
    recur(cnt, i + 1);

    // i번째 재료 선택
    flag[i] = true;
    recur(cnt - 1, i + 1);
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;

        min_diff = 2147483647;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
            flag[i] = false;
        }

        recur(N / 2, 0);

        cout << '#' << test_case << ' ' << min_diff << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}