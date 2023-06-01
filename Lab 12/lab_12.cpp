#include <iostream>
#include <stdio.h>

#define INFINITY 9999
#define max 6

using namespace std;


// Function to find the shortest path from a node to all other nodes using Dijkstra's algorithm
// Returns the average time taken to reach all other nodes from the start node

float dijsktras(int G[max][max], int n, int startnode)
{
    float average = 0;
    int distance[max];
    int last_nodes[max];
    bool visited[max];

    // Initialize all the arrays

    for (int i = 0; i < n; i++)
    {
        distance[i] = INFINITY;
        last_nodes[i] = NULL;
        visited[i] = 0;
    }

    // Intialize Distance of start node to 0

    distance[startnode] = 0;

    // Initialize count to 0
    int count = 0;


    // Loop until all the nodes are visited
    while (count < n - 1)
    {
        int min = INFINITY;
        int min_index = NULL;


        // Find the node with the minimum time duration
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i];
                min_index = i;
            }
        }


        int u = min_index;
        visited[min_index] = true;
        count++;

        // Update the distance array with the new minimum time duration
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && G[min_index][i] && distance[min_index] != INFINITY && distance[min_index] + G[min_index][i] < distance[i])
            {
                distance[i] = distance[min_index] + G[u][i];
                last_nodes[i] = min_index;
            }
        }
    }

    // Print the distance of each node from the start node
    for (int i = 0; i < n; i++)
    {
        if (i != startnode)
        {
            cout << "Distance of node " << i << " from node " << startnode << " is " << distance[i] << endl;
            average += distance[i];
            cout << "Path: ";
            int k = i;
            while (k != startnode)
            {
                cout << k << " <- ";
                k = last_nodes[k];
            }
            cout << startnode << endl;
        }
    }

    return average / (max - 1);
}

int main()
{
    //Define adjacency matrix with weights
    int G[max][max] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}};


    // Find the shortest path from each node to all other nodes and print the average time taken
    for (int i = 0; i < max; i++)
    {
        cout << "------------------------------------" << endl;
        cout << "Start node: " << i << endl;
        float average = dijsktras(G, max, i);
        cout << "Average time : " << average << endl;
    }
}