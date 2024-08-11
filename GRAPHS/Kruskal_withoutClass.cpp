#include <bits/stdc++.h>
using namespace std;

// Function to find the ultimate parent of a node
int findParent(int node, vector<int>& parent) {
    if (node == parent[node])
        return node;
    return parent[node] = findParent(parent[node], parent);
}

// Function to perform the union of two sets
void unionByRank(int u, int v, vector<int>& parent, vector<int>& rank) {
    int ulp_u = findParent(u, parent);
    int ulp_v = findParent(v, parent);
    
    if (ulp_u != ulp_v) {
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
}

// Function to add an edge to the adjacency list
void addEdge(int wt, int u, int v, vector<vector<int>>& adjList) {
    adjList.push_back({wt, u, v});
}

// Function to perform Kruskal's MST algorithm
int Kruskal_MST(int V, vector<vector<int>>& adjList) {
    // Sort edges in ascending order by weight
    sort(adjList.begin(), adjList.end());

    // Initialize parent and rank arrays
    vector<int> parent(V + 1), rank(V + 1, 0);
    for (int i = 0; i <= V; i++) {
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> mst;
    int minwt = 0;

    // Iterate through sorted edges
    for (auto edge : adjList) {
        int wt = edge[0];
        int u = edge[1];
        int v = edge[2];

        // Check if u and v belong to different sets
        if (findParent(u, parent) != findParent(v, parent)) {
            mst.push_back({wt, {u, v}});
            minwt += wt;
            unionByRank(u, v, parent, rank);
        }
    }

    // Print the edges in the MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto it : mst) {
        cout << it.second.first << " -- " << it.second.second << " weight = " << it.first << endl;
    }

    return minwt;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adjList;

    // Adding edges to the adjacency list
    addEdge(9, 5, 4, adjList);
    addEdge(4, 5, 1, adjList);
    addEdge(1, 4, 1, adjList);
    addEdge(5, 4, 3, adjList);
    addEdge(2, 1, 2, adjList);
    addEdge(3, 4, 2, adjList);
    addEdge(3, 3, 2, adjList);
    addEdge(7, 2, 6, adjList);
    addEdge(8, 3, 6, adjList);

    int minWeight = Kruskal_MST(V, adjList);
    cout << "Minimum weight of the spanning tree: " << minWeight << endl;

    return 0;
}
