//TC O(E * logV) 
//Kruskals Algorithm for finding Minimum spanning tree
//Ascending order sort acc of weight
//2 vertices u and v if not connected then only connect start from smallest edge
//Disjoin Set Union(DSU) bcz componets(nodes) are not joined before connecting if parent of u and v are diff
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int V) {
        rank.resize(V + 1);
        parent.resize(V + 1);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        // int root_u = findParent(u);
        // int root_v = findParent(v);
        // if (root_u != root_v) {
        //     if (rank[root_u] < rank[root_v]) {
        //         parent[root_u] = root_v;
        //     } else if (rank[root_u] > rank[root_v]) {
        //         parent[root_v] = root_u;
        //     } else {
        //         parent[root_v] = root_u;
        //         rank[root_u]++;
        //     }
        // }

        int ulp_u=findParent(u);      //find ultimate parent of u and v
    int ulp_v=findParent(v);
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
};

class Graph {
    int V;
public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int wt, int u, int v, vector<vector<int>>& adjList) {
        adjList.push_back({wt, u, v});
    }

    int Kruskal_MST(vector<vector<int>>& adjList) {
        sort(adjList.begin(), adjList.end());

        DisjointSet ds(V);
        vector<pair<int, pair<int, int>>> mst;
        int minwt = 0;

        for (auto edge : adjList) {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (ds.findParent(u) != ds.findParent(v)) {
                mst.push_back({wt, {u, v}});
                minwt += wt;
                ds.unionByRank(u, v);
            }
        }

        cout << "Edges in the Minimum Spanning Tree:\n";
        for (auto it : mst) {
            cout << it.second.first << " -- " << it.second.second << " weight = " << it.first << endl;
        }

        return minwt;
    }
};

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adjList;
    Graph g(V);

    // g.addEdge(10, 0, 1, adjList);   //wt , u, v
    // g.addEdge(15, 1, 3, adjList);
    // g.addEdge(4, 2, 3, adjList);
    // g.addEdge(6, 2, 0, adjList);
    // g.addEdge(5, 0, 3, adjList);

    // g.addEdge(2, 0, 1, adjList);
    // g.addEdge(1, 0, 2, adjList);
    // g.addEdge(1, 2, 1, adjList);
    // g.addEdge(2, 3, 2, adjList);
    // g.addEdge(1, 3, 4, adjList);
    // g.addEdge(2, 4, 2, adjList);

    g.addEdge(9, 5, 4, adjList);
    g.addEdge(4, 5, 1, adjList);
    g.addEdge(1, 4, 1, adjList);
    g.addEdge(5, 4, 3, adjList);
    g.addEdge(2, 1, 2, adjList);
    g.addEdge(3, 4, 2, adjList);
    g.addEdge(3, 3, 2, adjList);
    g.addEdge(7, 2, 6, adjList);
    g.addEdge(8, 3, 6, adjList);
    
    int minWeight = g.Kruskal_MST(adjList);
    cout << "Minimum weight of the spanning tree: " << minWeight << endl;

    return 0;
}
