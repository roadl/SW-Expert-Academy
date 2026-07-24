#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct node
{
    int n;
    int parent;
    int left;
    int right;
} Node;

void get_size(Node *nodes, int idx, int *cnt)
{
    if (nodes[idx].left != -1)
        get_size(nodes, nodes[idx].left, cnt);
    if (nodes[idx].right != -1)
        get_size(nodes, nodes[idx].right, cnt);
    (*cnt)++;
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int V, E, n1, n2;

        cin >> V >> E >> n1 >> n2;

        Node *nodes = (Node *)malloc(sizeof(Node) * (V + 1));
        int *arr = (int *)malloc(sizeof(int) * (V + 1));

        for (int i = 0; i <= V; i++)
        {
            nodes[i].n = i;
            nodes[i].parent = -1;
            nodes[i].left = -1;
            nodes[i].right = -1;
        }

        for (int i = 0; i < E; i++)
        {
            int t1, t2;

            cin >> t1 >> t2;

            if (nodes[t1].left == -1)
                nodes[t1].left = t2;
            else
                nodes[t1].right = t2;

            nodes[t2].parent = t1;
        }

        int size = 0;
        int find = -1;

        // for (int i = 1; i <= V; i++)
        //     printf("%d, parent: %d, left: %d, right: %d\n", i, nodes[i].parent, nodes[i].left, nodes[i].right);

        while (true)
        {
            arr[size++] = nodes[n1].parent;
            n1 = nodes[n1].parent;

            if (n1 == -1)
                break;
        }

        // for (int i = 0; i < size; i++)
        //     printf("arr[%d]: %d\n", i, arr[i]);

        while (true)
        {
            for (int i = 0; i < size; i++)
                if (nodes[n2].parent == arr[i])
                    find = arr[i];

            if (find != -1)
                break;

            n2 = nodes[n2].parent;
        }

        int cnt = 0;
        get_size(nodes, find, &cnt);

        printf("#%d %d %d\n", test_case, find, cnt);
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}