#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
 
int N, M, t;
 
vector<pair<int, int>> vec;
 
int cost(int size) {
    return (size * size) + (size - 1) * (size - 1);
}
 
int solve() {
    int size = N + 1;
    int max_cnt = 0;
    int cnt;
 
    while (cost(size) > vec.size() * M) size--;
 
    while (size > 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cnt = 0;
 
                for (auto v: vec)
                    if (abs(v.first - i) + abs(v.second - j) < size)
                        cnt++;
 
                if (cnt * M >= cost(size) && max_cnt < cnt) {
                     
                    max_cnt = cnt;
                }
            }
        }
 
        if (max_cnt != 0)
            return max_cnt;
 
        size--;
    }
 
    return -1;
}
 
int main(int argc, char **argv)
{
    int test_case;
    int T;
 
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
 
        cin >> N >> M;
 
        vec.clear();
 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> t;
 
                if (t == 1)
                    vec.push_back({i, j});
            }
        }
 
        printf("#%d %d\n", test_case, solve());
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}