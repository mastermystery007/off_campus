#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    vector<vector<pair<int,int>>> adj;
    Graph(int n)
    {
        adj.resize(n);
    }

    void addEdge(int u, int v, int w)
    {
        //add an edge from u to v with weight w

    }

    int find_shortest_path(int src, int dest)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //implement dijkstra's algorithm here
        return 0;
    }
};

int main()
{
    Graph g =  Graph(4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,2);
    
    
    return 0;
}