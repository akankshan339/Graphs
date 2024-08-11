#include<bits/stdc++.h>
using namespace std;

void Dfs_Of_Graph(int src ,int V ,vector<int>g[] ,vector<bool>& visited)
{
    visited[src]=true;
    cout<<src<<" , ";

    for(int v:g[src])
    {
        if(!visited[v])
            Dfs_Of_Graph(v , V, g, visited);
    }
}

void DFS(int V, vector<int>g[] ,int src)
{
    vector<bool>visited(V,false);
    Dfs_Of_Graph(src ,V ,g ,visited);

//this code is for if graph has disconnected components
 /*   for(int i=0;i<V;i++)
    {
        if(!visited[i])
        Dfs_Of_Graph(i ,V ,g ,visited);
    }*/
}

void addList(int u , int v ,vector<int>g[])
{
    g[u].push_back(v);    //for directed graph only in 1 direction
    g[v].push_back(u);    //for undirected graph both direction   u--->v and v--->u
}
int main()
{
    int V , src;
    cout<<"Enter no of vertices :";
    cin>>V;
    vector<int>g[V];    // Initialize adjacency list
    addList(0, 1 ,g);
    addList(0, 2 ,g);
    addList(1, 3 ,g);
    addList(2, 4 ,g);
    addList(1, 2 ,g);
    addList(3, 4 ,g);
    cout<<"Enter source node :";
    cin>>src;
    DFS(V,g ,src);
    
    return 0;
}