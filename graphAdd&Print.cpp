#include <iostream>
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

int main()
{
    graph *g = new graph(5);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 3, 2);
    addEdge(g, 3, 4);
    addEdge(g, 4, 0);

    printGraph(g);

    return 0;
}
