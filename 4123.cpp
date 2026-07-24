#include <iostream>
#include <stdio.h>

using namespace std;

// 0: 더하기, 1: 빼기, 2: 곱하기, 3: 나누기

int numbers[12];
int operators[11];
int operCnt[4];
int _max = -2147483648;
int _min = 2147483647;
int N;

int calculate()
{
    int result = numbers[0];

    for (int i = 0; i < N - 1; i++)
    {
        switch (operators[i])
        {
        case 0:
            result += numbers[i + 1];
            break;
        case 1:
            result -= numbers[i + 1];
            break;
        case 2:
            result *= numbers[i + 1];
            break;
        case 3:
            result /= numbers[i + 1];
            break;
        default:
            break;
        }
    }
    return result;
}

void solve(int cnt)
{
    if (cnt == N - 1)
    {
        int result = calculate();
        if (_max < result)
            _max = result;
        if (_min > result)
            _min = result;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operCnt[i] > 0)
        {
            operators[cnt] = i;
            operCnt[i]--;

            solve(cnt + 1);

            operCnt[i]++;
        }
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        _max = -2147483648;
        _min = 2147483647;

        cin >> N;

        for (int i = 0; i < 4; i++)
            cin >> operCnt[i];

        for (int i = 0; i < N; i++)
            cin >> numbers[i];

        solve(0);

        printf("#%d %d\n", test_case, _max - _min);
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}