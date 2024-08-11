//BFS traversal using adjencency List
/*     / 1 --- 3 
      0  |     |
       \ 2 --- 4        */
#include<bits/stdc++.h>
using namespace std;
void BFS(int src ,  vector<int>adjList[] ,vector<bool>&visited)
{
queue<int>q;
visited[src] = true;
q.push(src);

while(!q.empty())
{
    int curr=q.front();
    q.pop();
    cout<<curr<<" , ";

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
void addList(int u , int v ,vector<int>adjList[])
{
    adjList[u].push_back(v);    //for directed graph only in 1 direction
    adjList[v].push_back(u);    //for undirected graph both direction   u--->v and v--->u
}
int main()
{
    int V , src ;
    cout<<"Enter the no of Vertices :";
    cin>>V;
    vector<int>adjList[V];
    addList(0, 1 ,adjList);
    addList(0, 2 ,adjList);
    addList(1, 3 ,adjList);
    addList(2, 4 ,adjList);
    addList(1, 2 ,adjList);
    addList(3, 4 ,adjList);
    vector<bool>visited(V, false);
    cout<<"Enter the source node :";
    cin>>src;
    BFS(src , adjList ,visited);

return 0;
}