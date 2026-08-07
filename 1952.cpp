#include <iostream>

using namespace std;

int charge[4];
int use[12];
int res;

void recur(int month, int cur_charge) {
    if (month >= 12) {
        if (cur_charge < res)
            res = cur_charge;
        return;
    }

    if (charge[0] * use[month] < charge[1])
        // 1일 이용권
        recur(month + 1, cur_charge + charge[0] * use[month]);
    else
        // 1달 이용권
        recur(month + 1, cur_charge + charge[1]);

    // 3달 이용권
    recur(month + 3, cur_charge + charge[2]);
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {

        for (int i = 0; i < 4; i++)
            cin >> charge[i];

        for (int i = 0; i < 12; i++)
            cin >> use[i];
        
        // 1년 이용권 초기 max
        res = charge[3];
        
        recur(0, 0);

        cout << '#' << test_case << ' ' << res << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}