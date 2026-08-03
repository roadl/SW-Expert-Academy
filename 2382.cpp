#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int N, M, K;

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };

vector<vector<int>> vec;

void move() {
    for (int i = 0; i < K; i++) {
        if (vec[i][4] == -1)
            continue;

        vec[i][0] += dy[vec[i][3]];
        vec[i][1] += dx[vec[i][3]];

        if (vec[i][0] == 0 || vec[i][1] == 0) {
            vec[i][2] /= 2;
            vec[i][3] += 1;
        } else if (vec[i][0] == N - 1 || vec[i][1] == N - 1) {
            vec[i][2] /= 2;
            vec[i][3] -= 1;
        }

        if (vec[i][2] == 0)
            vec[i][4] = -1;

        // printf("%d: %d, %d, %d, %d\n", i, vec[i][0], vec[i][1], vec[i][2], vec[i][3]);
    }
}

void check() {
    for (int i = 0; i < K; i++) {
        if (vec[i][4] == -1)
            continue;

        int max_idx = i;
        int sum = vec[i][2];

        for (int j = i + 1; j < K; j++) {
            if (vec[j][4] == -1)
                continue;

            if (vec[i][0] == vec[j][0] && vec[i][1] == vec[j][1]) {
                sum += vec[j][2];

                if (vec[max_idx][2] < vec[j][2])
                    max_idx = j;
                
                vec[j][4] = -1;
            } 
        }

        vec[i][2] = sum;
        vec[i][3] = vec[max_idx][3];
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M >> K;

        vec.resize(K);

        for (int i = 0; i < K; i++) {
            vec[i].resize(5);
            cin >> vec[i][0] >> vec[i][1] >> vec[i][2] >> vec[i][3];
            vec[i][4] = 0;
        }

        for (int i = 0; i < M; i++) {
            move();
            check();
        }

        int result = 0;

        for (int i = 0; i < K; i++)
            if (vec[i][4] == 0)
                result += vec[i][2];
        
        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}