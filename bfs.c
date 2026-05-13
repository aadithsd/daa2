#include <stdio.h>
#include <conio.h>

#define MAX 100

int queue[MAX];
int f = -1, r = -1;

void enqueue(int value) {
    if (r == MAX - 1) return;
    if (f == -1) f = 0;
    queue[++r] = value;
}

int dequeue() {
    if (f == -1 || f > r) return -1;
    return queue[f++];
}

void BFS(int graph[MAX][MAX], int n, int start) {
    int v[MAX];
    int i, nei, current;

    for(i = 0; i < n; i++)
        v[i] = 0;

    f = r = -1;

    v[start] = 1;
    enqueue(start);

    while (f != -1 && f <= r) {
        current = dequeue();
        printf("%d ", current);

        for (nei = 0; nei < n; nei++) {
            if (graph[current][nei] == 1 && !v[nei]) {
                v[nei] = 1;
                enqueue(nei);
            }
        }
    }
}

void main() {
    int n, start, i, j;
    int graph[MAX][MAX];

    clrscr();

    printf("Enter nodes: ");
    scanf("%d", &n);

    printf("Enter matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Start node: ");
    scanf("%d", &start);

    BFS(graph, n, start);

    getch();
}
