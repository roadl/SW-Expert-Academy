#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stdint.h>

using namespace std;

vector<int> flag;
vector<int> distances[2];
int N, M;
int res;

int cal_time() {
    int total_time = 0;
    int stair = 0;
    int time = 0;

    vector<int> v;

    for (int i = 0; i < M; i++) {
        if (flag[i] == 1)
            v.push_back(distances[stair][i]);
    }

    sort(v.begin(), v.end());

    while (v[v.size() - 1] != 0) {
        time++;
        int cnt = 0;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0)
                continue;
            if (v[i] <= time && cnt < 3) {
                v[i]--;
                cnt++;
                continue;
            }
            break;
        }
    }

    if (total_time < time)
        time = total_time;

    return total_time;
}

int cal_dis(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

void dfs(int i) {
    // 그냥 각 사람 1인지 2인지만 DFS로
    // 사람이 사용할 계단 전부 정해지면 시간 계산 후 작은거로 확정
    if (i >= M) {
        int time = cal_time();

        if (res < time)
            time = res;

        return;
    }

    flag[i] = 1;
    dfs(i + 1);

    // flag[i] = 2;
    // dfs(i + 1);
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        
        vector<pair<int, int>> people;
        int stairs[2][3];

        res = INT32_MAX;

        int stair_cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int t;

                cin >> t;

                if (t == 1)
                    people.push_back({i, j});
                else if (t != 0) {
                    stairs[stair_cnt][0] = i;
                    stairs[stair_cnt][1] = j;
                    stairs[stair_cnt][2] = t;

                    stair_cnt++;
                }
            }
        }

        M = people.size();

        distances[0].resize(M, 0);
        distances[1].resize(M, 0);
        flag.resize(M, 0);

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) 
                distances[j][i] = cal_dis(people[i].first, people[i].second, stairs[j][0], stairs[j][1]);
        }

        dfs(0);
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}