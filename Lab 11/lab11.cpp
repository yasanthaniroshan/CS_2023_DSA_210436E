#include <iostream>
using namespace std;

#define size 6

//finding minimum edge 
int FindMinimumEdge(int keys[],bool visited[])
{
    int min = INT_MAX;
    int minIndex;
    for(int i=0;i< size;i++)
    {
        if(visited[i]==false && keys[i]<min)
        {
            min = keys[i];
            minIndex = i;
        }
    }
    return minIndex;
}
//finding minimum spanning tree
void PrimMst(int Graph[size][size])
{
    int parent[size];
    int keys[size];
    bool visited[size];
    for(int i=0;i<size;i++)
    {
        keys[i] = INT_MAX;
        visited[i] = false;
    }
    keys[0] = 0;
    parent[0] = -1;
    for(int i=0;i<size-1;i++)
    {
        int u = FindMinimumEdge(keys,visited);
        visited[u] = true;
        for(int v=0;v<size;v++)
        {
            if(Graph[u][v] && visited[v]==false && Graph[u][v]<keys[v])
            {
                parent[v] = u;
                keys[v] = Graph[u][v];
            }
        }
    }
    for(int i=1;i<size;i++)
    {
        cout<<parent[i]<<"-"<<i<<" => "<<Graph[i][parent[i]]<<endl;
    }
}

int main()
{
    //Adjacent matrix
    int Graph[size][size] =
    {
        {0,3,0,0,0,1},
        {3,0,2,1,10,0},
        {0,2,0,3,0,5},
        {0,1,3,0,5,0},
        {0,10,0,5,0,4},
        {1,0,5,0,4,0}
    };
    PrimMst(Graph);
    return 0;
}