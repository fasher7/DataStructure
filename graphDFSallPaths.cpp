#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data = 0;
    node *next = nullptr;
    node(int v)
    {
        data = v;
    }
};

struct graph
{
    int numVertex = 0;
    node **adjList;
    graph(int V)
    {
        numVertex = V;
        adjList = new node *[numVertex];
        for (int i = 0; i < numVertex; ++i)
        {
            adjList[i] = nullptr;
        }
    }
};

void addEdge(graph *g, int src, int dest)
{
    node *n = new node(dest);
    n->next = g->adjList[src];
    g->adjList[src] = n;
}

void printGraph(graph *g)
{
    for (int i = 0; i < g->numVertex; ++i)
    {
        cout << i << ": ";
        node *x = g->adjList[i];
        while (x != nullptr)
        {
            cout << x->data << " ";
            x = x->next;
        }
        cout << endl;
    }
}

void printArray(int *arr, int c)
{
    for (int i = 0; i < c; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void dfsHelper(graph *g, int start, int end, bool *visited, int *arr, int c)
{
    visited[start] = true;
    arr[c] = start;
    c = c + 1;
    if (start == end)
    {
        printArray(arr, c);
    }
    node *n = g->adjList[start];
    while (n != nullptr)
    {
        if (!visited[n->data])
        {
            dfsHelper(g, n->data, end, visited, arr, c);
        }
        n = n->next;
    }
    visited[start] = false;
}

void dfs(graph *g)
{
    bool *visited = new bool[g->numVertex];
    for (int i = 0; i < g->numVertex; ++i)
    {
        visited[i] = false;
    }
    int *arr = new int[g->numVertex];
    for (int i = 0; i < g->numVertex; ++i)
    {
        arr[i] = -1;
    }
    dfsHelper(g, 0, 5, visited, arr, 0);
}

int main()
{
    graph *g = new graph(6);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 0, 3);
    addEdge(g, 2, 3);
    addEdge(g, 3, 5);
    addEdge(g, 1, 4);
    addEdge(g, 5, 4);

    printGraph(g);
    dfs(g);

    return 0;
}
