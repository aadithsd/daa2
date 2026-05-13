#include <stdio.h>
#include <conio.h>

#define MAX 10

int graph[MAX][MAX], v[MAX];
int n, i;

void DFS(int node) {
    v[node] = 1;
    printf("%d ", node);

    for(i = 0; i < n; i++) {
        if(graph[node][i] == 1 && !v[i])
            DFS(i);
    }
}

void main() {
    int start, i, j;

    clrscr();

    printf("Enter vertices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        v[i] = 0;

    printf("Enter matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Start node: ");
    scanf("%d", &start);

    DFS(start);

    getch();
}
