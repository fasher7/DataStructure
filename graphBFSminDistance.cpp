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

int bfs(graph *g, int start, int end)
{
    queue<int> q;
    bool *isVisited = new bool[g->numVertex];
    for (int i = 0; i < g->numVertex; ++i)
    {
        isVisited[i] = false;
    }
    q.push(start);
    isVisited[start] = true;
    int qsize = q.size(); 
    int minD = 0;
    while (!q.empty())
    {
        int p = q.front();
        if (p == end)
        {
            return minD;
        }
        q.pop();
        qsize = qsize-1;

        node *n = g->adjList[p];
        while (n != nullptr)
        {
            if (isVisited[n->data] == false)
            {
                q.push(n->data);
                isVisited[n->data] = true;
            }
            n = n->next;
        }
        if (qsize == 0)
        {
            minD++;
            qsize = q.size();
        }
    }
    return 0;
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
    cout << bfs(g, 0, 5) << endl;

    return 0;
}
