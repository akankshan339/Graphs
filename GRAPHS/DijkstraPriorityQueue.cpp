//single source shortest path using priority queue
#include<bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(int src, int V, vector<vector<pair<int,int>>>&adjList)
{
priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>>pq;     //min heap shortest dist
vector<int>dist(V, INT_MAX);    //INT_MAX

dist[src] = 0;      //dist of src node to itself is 0
pq.push({0, src});
while(!pq.empty())
{
    int dis = pq.top().first;
    int node =pq.top().second;
    pq.pop();

    for(auto &adjnode:adjList[node])
    {
        int d = adjnode.first;
        int u = adjnode.second;       
        if( dis + d < dist[u])
        {
            dist[u] = dis + d;
            pq.push({dis+d, u});
        }
    }

}
return dist;
}

void addEdges(int src,int dest, int dist, vector<vector<pair<int, int>>>&adjList)
{
    adjList[src].push_back({dist, dest});
    adjList[dest].push_back({dist, src});
}
int main()
{
    int V,src;
    cout<<"Enter the no of vertices: ";
    cin>>V;
    cout<<"Enter the source node: ";
    cin>>src;
    vector<vector<pair<int, int>>>adjList(V);
//vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    // addList(0, 1, 1, adjList);
    // addList(0, 2, 6, adjList);
    // addList(1, 2, 3, adjList);
    
    addEdges(0, 2, 6, adjList);
    addEdges(0, 1, 2, adjList);
    addEdges(2, 3, 8, adjList);
    addEdges(1, 3, 5, adjList);
    addEdges(3, 4, 10, adjList);
    addEdges(3, 5, 15, adjList);
    addEdges(4, 6, 2, adjList);
    addEdges(5, 6, 6, adjList);

    vector<int> res=Dijkstra(src, V, adjList);
    cout<<"shortest path from "<<src<<" to every node of graph are \n";
    for (int i = 0; i < V; i++)
    {
        cout<<"shortest path from "<<src<<" to node  "<<i <<" is "<< res[i]<<endl;
       // cout << res[i] << " ";
    }
    return 0;
}