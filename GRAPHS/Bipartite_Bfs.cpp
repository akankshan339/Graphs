/*Bipartite graph which can be coloured using 2 colours such that no adjacent nodes have the same colour.
linear graph with no cycle is always bipartite graph. 
With cycle, graph with even cycle length is also bipartite graph. 
graph with odd cycle length can never be bipartite graph.
Brute force filling colours using any traversal technique, make sure no 2 adjacent nodes have same colour.
If at any moment of traversal adjacent nodes have same colour, i.e odd cycle, not bipartite graph. */
#include<bits/stdc++.h>
using namespace std;
bool check(int V, int src, vector<int>adjList[], vector<int>&colour)
{
    queue<int>q;
    q.push(src);
    colour[src]=1;          //assuming 2 colour as 0 and 1 let 1st node colour is 1
    while(!q.empty())
    {
        int node =q.front();
        q.pop();

        for(int adjnode:adjList[node])
        {
            if(colour[adjnode] == -1)       //if adjacent node not colored give opposite color of node 
            {
                colour[adjnode] = !colour[node];
                q.push(adjnode);
            }
            else if(colour[adjnode] == colour[node])
                return false;
        }
    
    }
    return true;
}

bool BipartiteBfs(int V, vector<int>adjList[])
{
    vector<int>colour(V,-1);
for(int i =0 ;i<V;i++)              //Disconnected Graphs components 
    {
        if(colour[i]== -1)    // if not coloured
        {
        if(check(V, i, adjList, colour) == false)
        return false; 
        }
    }
    return true;
}
void addList(int u, int v, vector<int>adjList[])
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main()
{
    int V, src;
    cout<<"Enter the no of vertices: ";
    cin>>V;
    vector<int>adjList[V];
    
    addList(0, 2, adjList);     //eg 1 to check non bipartite graph
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


    bool res=BipartiteBfs(V, adjList);
    if(res == true)
    cout<<"Bipartite Graph!!! ";
    else
    cout<<"Not Bipartite Graph!!! ";
    
    return 0;
}