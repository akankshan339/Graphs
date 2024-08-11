//BFS tarverasl for directed and undirected graph taking edges from user input
#include<bits/stdc++.h>
using namespace std;
void BFS(int src , unordered_map<int , vector<int>>&adjList , vector<bool>&visited ,vector<int>&res)
{
queue<int>q;
visited[src]=true;
q.push(src);

while(!q.empty())
{
    int curr=q.front();
    q.pop();
    //cout<<curr<<" , ";
    res.push_back(curr);

    for(int v:adjList[curr])
    {
        if(!visited[v])
        {
            visited[v]=true;
            q.push(v);
        }
    }
}
}
void addList(int u , int v , unordered_map<int, vector<int>> &adjList)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
int main()
{
    int V ,edges, src , u , v;
    cout<<"Enter the no of Vertices :";
    cin>>V;
    unordered_map<int , vector<int>>adjList(V);     //vector<vector<int>> adjmat(V); //for adjencency matrix
    cout<<"Enter the no of Edges :";
    cin>>edges;
    cout<<"Enter edges :\n";
    for(int i =0 ;i<edges;i++)          //taking edges from user input
    {
        cin>>u>>v;
        addList(u , v, adjList);
    }
    cout<<"Enter source node :";
    cin>>src;
    vector<bool>visited(V, false);
    vector<int>res(V);
    BFS(src ,adjList, visited ,res);

    cout<<"BFS tarversal considering "<< src <<"as source node \n";
    for(int i=0;i<V;i++)
    {
        cout<<res[i]<<" , ";
    }
    return 0;
}