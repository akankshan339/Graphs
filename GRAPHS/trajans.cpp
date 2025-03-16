#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
vector<vector<int>> SCCs;
int disc[MAXN], low[MAXN], inStack[MAXN];
stack<int> st;
int timer = 0;

void tarjanDFS(int u)
{
    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = 1;

    for (int v : graph[u])
    {
        if (disc[v] == -1)
        {
            tarjanDFS(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u])
    {
        vector<int> scc;
        while (true)
        {
            int v = st.top();
            st.pop();
            inStack[v] = 0;
            scc.push_back(v);
            if (v == u)
                break;
        }
        SCCs.push_back(scc);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low));
    memset(inStack, 0, sizeof(inStack));

    for (int i = 1; i <= n; i++)
    {
        if (disc[i] == -1)
        {
            tarjanDFS(i);
        }
    }

    cout << "Strongly Connected Components:\n";
    for (auto &scc : SCCs)
    {
        for (int v : scc)
            cout << v << " ";
        cout << "\n";
    }
    return 0;
}
