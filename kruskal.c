#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

Edge e[MAX], res[MAX];
int p[MAX];

void makeSet(int n) {
    int i;
    for (i = 0; i < n; i++)
        p[i] = i;
}

int find(int i) {
    while (p[i] != i)
        i = p[i];
    return i;
}

void unionSet(int u, int v) {
    int ru = find(u);
    int rv = find(v);
    p[ru] = rv;
}

/* Comparator for qsort */
int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return (e1->weight - e2->weight);
}

void main() {
    int V, E, i, u, v;
    int mstSize = 0, totalWeight = 0;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].weight);
    }

    makeSet(V);

    /* Sorting edges using qsort */
    qsort(e, E, sizeof(Edge), compare);

    for (i = 0; i < E; i++) {
        u = e[i].u;
        v = e[i].v;

        if (find(u) != find(v)) {
            res[mstSize++] = e[i];
            unionSet(u, v);
        }
    }

    printf("\nEdges in MST:\n");
    for (i = 0; i < mstSize; i++) {
        printf("%d -- %d == %d\n", res[i].u, res[i].v, res[i].weight);
        totalWeight += res[i].weight;
    }

    printf("Total weight of MST = %d", totalWeight);

    getch();
}
