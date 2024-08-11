//DFS traversal using adjencency List
/*     / 1 --- 3 
      0  |     |
       \ 2 --- 4          Ans: if src =0 ,1,3,4,2 or 0,2,4,3,1           */
#include<bits/stdc++.h>
using namespace std;
void DFS(int src , vector<int> adjList[] ,vector<bool>&visited)
{
visited[src]=true;
cout<<src<<" , ";

for(int v:adjList[src])
{
    if(!visited[v])
        DFS(v,adjList,visited);
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
    // addList(0, 1 ,adjList);
    // addList(0, 2 ,adjList);
    // addList(1, 3 ,adjList);
    // addList(2, 4 ,adjList);
    // addList(1, 2 ,adjList);
    // addList(3, 4 ,adjList);

    addList(0, 1 ,adjList);
    addList(2, 3 ,adjList);
    addList(0, 2 ,adjList);
    addList(2, 0 ,adjList);
    addList(1, 2 ,adjList);
    addList(3, 3 ,adjList);
    
    // addList(1, 2 ,adjList);
    // addList(2, 5 ,adjList);
    // addList(2, 6 ,adjList);
    // addList(1, 3 ,adjList);
    // addList(3, 4 ,adjList);
    // addList(3, 7 ,adjList);
    // addList(4, 8 ,adjList);
    // addList(7, 8 ,adjList);
    vector<bool>visited(V, false);
    cout<<"Enter the source node :";
    cin>>src;
    DFS(src , adjList ,visited);
return 0;
}