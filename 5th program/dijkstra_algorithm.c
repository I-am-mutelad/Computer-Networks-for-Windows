#include <stdio.h>
#include <limits.h>

void main() {
    int vertices, paths;
    // Prompt for the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Define the cost matrix and path arrays based on the number of vertices
    int costMatrix[vertices + 1][vertices + 1];
    int path[100][vertices + 1], totalCost[100];
    int start = 1, end = vertices, minCost, minCostPathIndex;

    // Input cost matrix
    printf("Enter the cost matrix (%dx%d):\n", vertices, vertices);
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            // Input the cost matrix values
            scanf("%d", &costMatrix[i][j]);
        }
    }

    // Input number of paths
    printf("Enter the number of paths: ");
    scanf("%d", &paths);

    // Input possible paths
    printf("Enter the possible paths (each path should have up to %d vertices):\n", vertices);
    for (int i = 1; i <= paths; i++) {
        for (int j = 1; j <= vertices; j++) {
            // Input the possible paths
            scanf("%d", &path[i][j]);
        }
    }

    // Calculate the cost of each path
    for (int i = 1; i <= paths; i++) {
        totalCost[i] = 0;
        int current = start;
        for (int j = 1; j <= vertices; j++) {
            int next = path[i][j];
            // Calculate the total cost for each path
            totalCost[i] += costMatrix[current][next];
            if (next == end) break;
            current = next;
        }
    }

    // Find the minimum cost and the corresponding path
    minCost = totalCost[1];
    minCostPathIndex = 1;
    for (int i = 1; i <= paths; i++) {
        // Determine the minimum cost and its corresponding path index
        if (totalCost[i] < minCost) {
            minCost = totalCost[i];
            minCostPathIndex = i;
        }
    }

    // Output the minimum cost and the corresponding path
    printf("Minimum cost: %d\n", minCost);
    printf("Minimum cost path: ");
    for (int i = 1; i <= vertices; i++) {
        // Output the path with minimum cost
        printf("%d", path[minCostPathIndex][i]);
        if (path[minCostPathIndex][i] == end) break;
        if (i < vertices) printf(" --> ");
    }
    printf("\n");
}
