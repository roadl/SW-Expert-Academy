#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, M;

        cin >> N >> M;

        bool flag = true;

        for (int i = 1; i <= N; i++)
        {
            if ((M & (1 << (i - 1))) == 0)
            {
                flag = false;
                break;
            }
        }

        printf("#%d %s\n", test_case, (flag ? "ON" : "OFF"));
    }
    return 0;
}