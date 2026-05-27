/* ============================================================
 * Mini Project: Kahn's Algorithm for Topological Sorting
 * Algorithm   : Kahn's Algorithm
 * Description : Program to perform topological sorting using queue
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

/* Function to insert element into queue */
void enqueue(int value) {
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

/* Function to remove element from queue */
int dequeue() {
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}

/* Function to check if queue is empty */
int isEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int graph[MAX][MAX];
    int indegree[MAX];
    int vertices, edges;
    int i, j;
    int u, v;
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    /* Initialize graph and indegree array */
    for (i = 0; i < vertices; i++) {
        indegree[i] = 0;

        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");

    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        indegree[v]++;
    }

    /* Insert all vertices with indegree 0 into queue */
    for (i = 0; i < vertices; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("\nTopological Order:\n");

    while (!isEmpty()) {
        int current = dequeue();

        printf("%d ", current);
        count++;

        for (i = 0; i < vertices; i++) {
            if (graph[current][i] == 1) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    /* Check for cycle */
    if (count != vertices) {
        printf("\nGraph contains a cycle. Topological sorting not possible.\n");
    }

    return 0;
}