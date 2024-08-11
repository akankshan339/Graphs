#include<bits/stdc++.h>
using namespace std;
bool dfs(int src, int col, vector<int>adjList[], vector<int>&colour)
{
    colour[src] = col;

    for(int adjnode : adjList[src])         // traverse adjacent nodes
    {
        if(colour[adjnode] == -1)           //if uncoloured
        {
            if(dfs(adjnode, !col, adjList, colour) == false)
                return false;          
        }
        else if(colour[adjnode] == col)         //if previously coloured and have same colour
                return false; 
    }
   
return true;
}

bool isBipartite(int V, vector<int>adjList[])
{
vector<int>colour(V,-1);
for(int i =0; i<V; i++)         // for connected components
{
    if(colour[i] == -1)
    {
        if(dfs(i, 1, adjList, colour) == false)    //passing 1 as colour of 1st node
            return false;

    }
}
return true;
}

void addList(int u , int v, vector<int>adjList[])
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
int main()
{
    int V;
    cout<<"Enter no of vertices: ";
    cin>>V;
    vector<int>adjList[V];
    addList(0, 2, adjList);     //eg 1 to check bipartite graph
    addList(0, 3, adjList);
    addList(2, 3, adjList);
    addList(3, 1, adjList);

    // addList(1, 2, adjList);     //eg 1 to check Non bipartite graph
    // addList(2, 3, adjList);
    // addList(2, 6, adjList);
    // addList(3, 4, adjList);
    // addList(4, 5, adjList);
    // addList(4, 7, adjList);
    // addList(2, 3, adjList);
    // addList(7, 8, adjList);


    // cout<<"Enter the source node: ";
    // cin>>src;
   
    bool res=isBipartite(V, adjList);
    if(res == true)
    cout<<"Bipartite Graph!!! ";
    else
    cout<<"Not Bipartite Graph!!! ";
    
    return 0;
}