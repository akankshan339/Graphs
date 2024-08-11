//prims algo using priority queue
#include <bits/stdc++.h>
using namespace std;

int prims(int V, vector<vector<pair<int, int>>>& adjList) {
    int mstSum = 0;
    //by default priority_queue is max heap so we convert it to min heap min wt on top
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
    vector<int> vis(V, 0);
//Starting with node 0 and weight 0
    pq.push({0, 0}); // 1st push wt then node
/*Even though the priority queue stores pairs in the format {weight, node}, the adjacency list stores them as {node, weight}*/
    while (!pq.empty()) {
        auto it = pq.top();
        int wt = it.first;      //prioritizing on bases of weight
        int node = it.second;
        pq.pop();

        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        mstSum += wt;

/*Each adjList[node] is a vector of pairs where each pair represents an adjacent node and the edge weight to that node:

pair<int, int> where first is the adjacent node, and second is the weight of the edge connecting to that node.*/
        for (auto it : adjList[node]) {
            int adjNode = it.first;
            int edWt = it.second;
            if (!vis[adjNode])
                pq.push({edWt, adjNode});
        }
    }
    return mstSum;
}

//{parent , (node, wt)}
// [ {0, (1, 2)} , {0, (2, 1)} , {1, (2,1)} , {2, (3,2)} , {3, (4,1)} , {4, (2, 2)}]
void addEdge(int parent, int node, int wt, vector<vector<pair<int, int>>>& adjList) {
    adjList[parent].push_back({node, wt});
    adjList[node].push_back({parent, wt});  //for undirected graph both line of code
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<pair<int, int>>> adjList(V);

    addEdge(0, 1, 2, adjList); // parent, node, weight
    addEdge(0, 2, 1, adjList);
    addEdge(1, 2, 1, adjList);
    addEdge(2, 3, 2, adjList);
    addEdge(3, 4, 1, adjList);
    addEdge(4, 2, 2, adjList);

    int mstwt = prims(V, adjList);
    cout << "Total weight of MST is: " << mstwt << endl;
    return 0;
}
/*priority_queue<pair<int, int>>:
This part declares a priority queue that will store elements of type pair<int, int>. 
Each element is a pair, where 1st integer represents weight of an edge, and 2nd integer represents node connected by that edge.

The queue uses a vector<pair<int, int>> as its underlying container to store the elements.

queue is ordered using greater<pair<int, int>> comparator, meaning element with smallest pair 
(by the first element of pair primarily) will be at top of priority queue.*/


/*This line creates a priority queue that behaves as a min heap. Here's the breakdown:

pair<int, int>: The type of elements stored in the priority queue. In this case, it's a pair where the first element is the weight and the second is the node.
vector<pair<int, int>>: The underlying container used to store the elements.
greater<pair<int, int>>: The comparator used to order the elements. Using greater ensures that the smallest element is always at the top of the heap.*/