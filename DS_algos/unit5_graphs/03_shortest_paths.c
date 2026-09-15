/**
 * Unit 5 — Shortest Path Algorithms
 * Topics:
 *   - Dijkstra's Algorithm (Single Source Shortest Path for Non-Negative Edge Weights)
 *   - Shortest Path Reconstruction (Path Tracking)
 *   - Floyd-Warshall Algorithm (All-Pairs Shortest Path Dynamic Programming)
 *   - Edge Case Handling & Complexity Verification
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX_V 10
#define INF 999999

/* ========================================================================= */
/* 1. Dijkstra's Algorithm (Single Source Shortest Path)                     */
/* ========================================================================= */

void dijkstra(int graph[MAX_V][MAX_V], int num_vertices, int src, int dist[MAX_V], int parent[MAX_V]) {
    bool visited[MAX_V];

    for (int i = 0; i < num_vertices; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < num_vertices - 1; count++) {
        /* Choose the unvisited vertex with minimum distance */
        int min_val = INF, u = -1;
        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && dist[v] <= min_val) {
                min_val = dist[v];
                u = v;
            }
        }

        if (u == -1 || dist[u] == INF) break;
        visited[u] = true;

        /* Relax adjacent vertices */
        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

/* ========================================================================= */
/* 2. Floyd-Warshall Algorithm (All-Pairs Shortest Path)                     */
/* ========================================================================= */

void floyd_warshall(int graph[MAX_V][MAX_V], int num_vertices, int dist[MAX_V][MAX_V]) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            } else {
                dist[i][j] = INF;
            }
        }
    }

    /* Dynamic programming relaxation over intermediate vertices k */
    for (int k = 0; k < num_vertices; k++) {
        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

/* ========================================================================= */
/* Verification & Test Harness                                               */
/* ========================================================================= */

int main(void) {
    printf("========================================================\n");
    printf("   Unit 5: Shortest Path Algorithms\n");
    printf("========================================================\n\n");

    /* Graph with 5 vertices (0 through 4)
     * (0)->(1): 10, (0)->(3): 5
     * (1)->(2): 1,  (1)->(3): 2
     * (3)->(1): 3,  (3)->(2): 9, (3)->(4): 2
     * (2)->(4): 4
     * (4)->(0): 7,  (4)->(2): 6
     */
    int num_vertices = 5;
    int graph[MAX_V][MAX_V] = {
        {0, 10,  0,  5,  0},
        {0,  0,  1,  2,  0},
        {0,  0,  0,  0,  4},
        {0,  3,  9,  0,  2},
        {7,  0,  6,  0,  0}
    };

    /* 1. Dijkstra from source 0 */
    int dist[MAX_V];
    int parent[MAX_V];
    dijkstra(graph, num_vertices, 0, dist, parent);

    printf("Dijkstra Shortest Distances from Vertex 0:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("  To Vertex %d: %d\n", i, dist[i]);
    }

    /* Expected distances from 0:
     * 0 -> 0 = 0
     * 0 -> 3 = 5
     * 0 -> 1 via 3 = 5 + 3 = 8
     * 0 -> 2 via 3 -> 1 = 8 + 1 = 9
     * 0 -> 4 via 3 = 5 + 2 = 7
     */
    assert(dist[0] == 0);
    assert(dist[3] == 5);
    assert(dist[1] == 8);
    assert(dist[4] == 7);
    assert(dist[2] == 9);

    /* 2. Floyd-Warshall All-Pairs */
    int all_pairs[MAX_V][MAX_V];
    floyd_warshall(graph, num_vertices, all_pairs);

    printf("\nFloyd-Warshall Distances from Vertex 0:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("  To Vertex %d: %d\n", i, all_pairs[0][i]);
        assert(all_pairs[0][i] == dist[i]);
    }

    printf("\n[PASS] All Shortest Path tests passed successfully!\n");
    return 0;
}
