#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

int M, A;

vector<vector<int>> AP_vec;

vector<int> move_a;
vector<int> move_b;

int a_x, a_y, b_x, b_y;

int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, -1, 0, 1, 0 };

int cal_dis(int n1_x, int n1_y, int n2_x, int n2_y) {
    return abs(n1_x - n2_x) + abs(n1_y - n2_y);
}

// AP가 정렬 돼 있으면 앞에서 부터 보면서 하나 픽하고 나머지 픽하면 될텐데 그져
int charge() {
    int charge = 0;

    // 0이면 하나도 못 찾음, 1이면 A 찾음, 2면 B 찾음, 3이면 A, B 둘다 같이 큰거
    int flag = 0;

    for (int i = 0; i < A; i++) {
        int check = 0;
        int a_dis = cal_dis(AP_vec[i][0], AP_vec[i][1], a_x, a_y);
        int b_dis = cal_dis(AP_vec[i][0], AP_vec[i][1], b_x, b_y);
        if (a_dis <= AP_vec[i][2])
            check += 1;
        if (b_dis <= AP_vec[i][2])
            check += 2;

        if (check == 0)
            continue;

        if (flag == 0) {
            charge += AP_vec[i][3];

            flag = check;
        } else if (flag == 1 && check >= 2) {
            charge += AP_vec[i][3];
            break;
        } else if (flag == 2 && (check & 1)) {
            charge += AP_vec[i][3];
            break;
        } else if (flag == 3) {
            charge += AP_vec[i][3];
            break;
        }
    }
    
    return charge;
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> M >> A;

        move_a.resize(M);
        move_b.resize(M);

        for (int i = 0; i < M; i++)
            cin >> move_a[i];

        for (int i = 0; i < M; i++)
            cin >> move_b[i];

        AP_vec.resize(A);

        for (int i = 0; i < A; i++) {
            AP_vec[i].resize(4);
            for (int j = 0; j < 4; j++) {
                cin >> AP_vec[i][j];
            }
        }

        sort(AP_vec.begin(), AP_vec.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[3] > b[3];
        });

        
        a_x = 1, a_y = 1;
        b_x = 10, b_y = 10;

        int total = 0;
        
        total += charge();

        for (int i = 0; i < M; i++) {
            a_x += dx[move_a[i]];
            a_y += dy[move_a[i]];
            b_x += dx[move_b[i]];
            b_y += dy[move_b[i]];
            
            total += charge();
        }

        printf("#%d %d\n", test_case, total);
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}