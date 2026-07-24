#include <iostream>

using namespace std;

typedef struct node
{
    int x;
    int y;
} Node;

int abs(int n)
{
    return (n < 0 ? -n : n);
}

int get_distance(Node n1, Node n2)
{
    return abs(n1.x - n2.x) + abs(n1.y - n2.y);
}

Node nodes[12];
bool flag[10];
int min_dis = 3000;
int N;

void dfs(int cur, int dis, int cnt)
{
    if (dis >= min_dis)
        return;

    if (cnt == 0)
    {
        dis += get_distance(nodes[cur], nodes[0]);
        if (dis < min_dis)
            min_dis = dis;
        return;
    }

    for (int i = 2; i < N + 2; i++)
    {
        if (flag[i] == true)
            continue;

        int new_dis = get_distance(nodes[cur], nodes[i]);

        flag[i] = true;

        dfs(i, dis + new_dis, cnt - 1);

        flag[i] = false;
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        min_dis = 3000;

        for (int i = 0; i < N + 2; i++)
        {
            cin >> nodes[i].x >> nodes[i].y;
            flag[i] = false;
        }

        dfs(1, 0, N);

        printf("#%d: %d\n", test_case, min_dis);
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}