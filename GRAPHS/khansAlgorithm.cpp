#include <bits/stdc++.h>
using namespace std;

vector<int> kahnsAlgorithm(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0), topo;
    queue<int> q;

    for (int i = 0; i < V; i++)
        for (int v : adj[i])
            indegree[v]++;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : adj[u])
        {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }
    return topo;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> topo = kahnsAlgorithm(V, adj);

    for (int node : topo)
        cout << node << " ";

    return 0;
}
