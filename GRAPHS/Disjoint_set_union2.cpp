//Method 2 : Union by size
#include<bits/stdc++.h>
using namespace std;

int findParent(int node ,vector<int>&parent)
{
if(node == parent[node])
    return node;
return parent[node] = findParent(parent[node] , parent);
}
void UnionBySize(int u , int v , vector<int> &parent, vector<int>&size)
{
int ulp_u = findParent(u , parent);
int ulp_v = findParent(v , parent);
if(ulp_u == ulp_v)
    return;
// else if(size[ulp_u] > size[ulp_v])
//     parent[ulp_v] = ulp_v;
// else if(size[ulp_u] < size[ulp_v])
//     size[ulp_u] = ulp_v;
// else
//     {
//         parent[ulp_u] = ulp_v;
//         size[ulp_v] +=size[ulp_u];
//     }
if(size[ulp_u] < size[ulp_v])
{
    parent[ulp_u] = ulp_v;
    size[ulp_v] += size[ulp_u];
}
else
{
    parent[ulp_v] = ulp_u;
    size[ulp_u] += size[ulp_v];
}
}

int main()
{
    int V;
    cout<<"Enter the no of vertices :";
    cin>>V;
    vector<int> parent ,size;
    parent.resize(V+1);
    size.resize(V+1);
    for(int i =0; i<=V; i++)
    {
        parent[i]=i;
        size[i]=1;
    }
    UnionBySize(1,2,parent, size);
    UnionBySize(2,3,parent, size);
    UnionBySize(4,5,parent, size);
    UnionBySize(6,7,parent, size);
    UnionBySize(5,6,parent, size);

    if(findParent(3 ,parent) == findParent(7 ,parent))
        cout<<"Same \n";
    else
        cout<<"Not Same \n";

    UnionBySize(3,7,parent, size);

    if(findParent(3 ,parent) == findParent(7 ,parent))
        cout<<"Same \n";
    else
        cout<<"Not Same \n";
    return 0;
}