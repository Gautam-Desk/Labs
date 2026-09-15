/**
 * Unit 5 — Graph Representations & Traversals
 * Topics:
 *   - Adjacency Matrix Representation
 *   - Adjacency List Representation
 *   - Breadth-First Search (BFS) using Queue
 *   - Depth-First Search (DFS) using Recursion
 *   - Connected Components Detection
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_VERTICES 20
#define QUEUE_SIZE 64

/* ========================================================================= */
/* 1. Adjacency List Data Structure                                          */
/* ========================================================================= */

typedef struct AdjListNode {
    int dest;
    struct AdjListNode *next;
} AdjListNode;

typedef struct Graph {
    int num_vertices;
    AdjListNode *adj_lists[MAX_VERTICES];
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

AdjListNode *create_adj_node(int dest) {
    AdjListNode *node = (AdjListNode *)malloc(sizeof(AdjListNode));
    if (!node) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }
    node->dest = dest;
    node->next = NULL;
    return node;
}

Graph *create_graph(int vertices) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->num_vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->adj_lists[i] = NULL;
        for (int j = 0; j < vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
    return g;
}

void add_edge(Graph *g, int src, int dest, bool undirected) {
    /* Adjacency Matrix */
    g->adj_matrix[src][dest] = 1;
    if (undirected) {
        g->adj_matrix[dest][src] = 1;
    }

    /* Adjacency List */
    AdjListNode *node = create_adj_node(dest);
    node->next = g->adj_lists[src];
    g->adj_lists[src] = node;

    if (undirected) {
        node = create_adj_node(src);
        node->next = g->adj_lists[dest];
        g->adj_lists[dest] = node;
    }
}

void free_graph(Graph *g) {
    if (!g) return;
    for (int i = 0; i < g->num_vertices; i++) {
        AdjListNode *curr = g->adj_lists[i];
        while (curr) {
            AdjListNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(g);
}

/* ========================================================================= */
/* 2. Breadth-First Search (BFS)                                             */
/* ========================================================================= */

void bfs(const Graph *g, int start_vertex, int *traversal_out, int *count) {
    *count = 0;
    bool visited[MAX_VERTICES] = {false};
    int queue[QUEUE_SIZE];
    int front = 0, rear = 0;

    visited[start_vertex] = true;
    queue[rear++] = start_vertex;

    while (front < rear) {
        int v = queue[front++];
        traversal_out[(*count)++] = v;

        /* Traverse neighbors via adjacency matrix */
        for (int neighbor = 0; neighbor < g->num_vertices; neighbor++) {
            if (g->adj_matrix[v][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
        }
    }
}

/* ========================================================================= */
/* 3. Depth-First Search (DFS)                                               */
/* ========================================================================= */

static void dfs_util(const Graph *g, int v, bool visited[], int *traversal_out, int *count) {
    visited[v] = true;
    traversal_out[(*count)++] = v;

    for (int neighbor = 0; neighbor < g->num_vertices; neighbor++) {
        if (g->adj_matrix[v][neighbor] && !visited[neighbor]) {
            dfs_util(g, neighbor, visited, traversal_out, count);
        }
    }
}

void dfs(const Graph *g, int start_vertex, int *traversal_out, int *count) {
    *count = 0;
    bool visited[MAX_VERTICES] = {false};
    dfs_util(g, start_vertex, visited, traversal_out, count);
}

/* ========================================================================= */
/* 4. Connected Components                                                   */
/* ========================================================================= */

int count_connected_components(const Graph *g) {
    bool visited[MAX_VERTICES] = {false};
    int components = 0;

    for (int i = 0; i < g->num_vertices; i++) {
        if (!visited[i]) {
            int dummy_out[MAX_VERTICES];
            int count = 0;
            dfs_util(g, i, visited, dummy_out, &count);
            components++;
        }
    }
    return components;
}

/* ========================================================================= */
/* Verification & Test Harness                                               */
/* ========================================================================= */

int main(void) {
    printf("========================================================\n");
    printf("   Unit 5: Graph Representations & Traversals\n");
    printf("========================================================\n\n");

    /* Create an undirected graph with 6 vertices (0 through 5):
     * 0 --- 1 --- 2
     * |     |
     * 3 --- 4     5 (isolated component)
     */
    Graph *g = create_graph(6);
    add_edge(g, 0, 1, true);
    add_edge(g, 0, 3, true);
    add_edge(g, 1, 2, true);
    add_edge(g, 1, 4, true);
    add_edge(g, 3, 4, true);

    int buffer[MAX_VERTICES];
    int count = 0;

    /* BFS from vertex 0 */
    bfs(g, 0, buffer, &count);
    printf("BFS Traversal from 0: ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");
    assert(count == 5);
    assert(buffer[0] == 0);

    /* DFS from vertex 0 */
    count = 0;
    dfs(g, 0, buffer, &count);
    printf("DFS Traversal from 0: ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");
    assert(count == 5);
    assert(buffer[0] == 0);

    /* Connected components: {0,1,2,3,4} and {5} -> 2 components */
    int components = count_connected_components(g);
    printf("\nConnected Components: %d (Expected: 2)\n", components);
    assert(components == 2);

    free_graph(g);
    printf("\n[PASS] All Graph Representation & Traversal tests passed successfully!\n");
    return 0;
}
