//Method 1 : Union by Rank
//Disjoint set Union (DSU) or Union Find ,sets whoes intersection is NULL
//2 operations  (i)combine 2 given sets  (ii)Tell if 2 members eg a,b belong to same set or not
//(i)find parent() or findSet() , (ii) Union()  or UnionSet() by rank or by size

#include<bits/stdc++.h>
using namespace std;

int findU_Parent(int node ,vector<int>&parent)
{
if(node == parent[node])            //if node itself is its parent
    return node;

//findU_Parent(parent[node] , parent);                    //without path compression
parent[node] = findU_Parent(parent[node] , parent);     //with path compression

return parent[node];
}

void UnionByRank(int u , int v ,vector<int> &rank , vector<int> &parent)
{
    int ulp_u=findU_Parent(u, parent);      //find ultimate parent of u and v
    int ulp_v=findU_Parent(v, parent);
    if(ulp_u == ulp_v)
        return;
    else if(rank[ulp_u] < rank[ulp_v])
        parent[ulp_u] = ulp_v;         //parent of u is v
    else if(rank[ulp_u]> ulp_v)
        parent[ulp_v] = ulp_u;          //parent of v is u
    else
    {                             //parent of u and v are same
        parent[ulp_u] = ulp_v;          //can make any parent u or v 
        rank[ulp_v]++;                  //++ rank of parent of either u or v outside if else
    }
}


int main()
{
    vector<int> rank , parent;
    int V;
    cout<<"Enter Total no of vertices :";
    cin>>V;
    rank.resize(V+1);
    parent.resize(V+1);
    for(int i=0; i<=V; i++)
    {
        rank[i] = 0;
        parent[i] =i;
    }
    UnionByRank(1, 2 ,rank ,parent);
    UnionByRank(2, 3 ,rank ,parent);
    UnionByRank(4, 5 ,rank ,parent);
    UnionByRank(6 ,7 ,rank ,parent);
    UnionByRank(5, 6 ,rank ,parent);
    //UnionByRank(3, 7 , rank , parent);
    if(findU_Parent(3 ,parent) == findU_Parent(7,parent))
        cout<<"Same \n";
        else
        cout<<"Not Same \n";

    UnionByRank(3, 7 , rank , parent);

    if(findU_Parent(3 ,parent) == findU_Parent(7,parent))
        cout<<"Same \n";
        else
        cout<<"Not Same \n";
    return 0;
}