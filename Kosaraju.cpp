
// time complexity : 0(V+E)  V = Vertex , E = Edge
// Kosaraju algorithm is used to find Strongly Connected Component of a graph



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz 10000

vector <ll> graph[sz];
vector <ll> transpose[sz];
bool vis[sz];
vector <ll> order;
vector <ll> curr;
vector <vector<ll> > scc;

void dfs(ll node)
{
    vis[node] = true;

    for (ll i = 0; i < graph[node].size(); i++)
    {
        ll next = graph[node][i];

        if (!vis[next])
            dfs(next);
    }

    order.push_back(node);
}

void dfs1(ll node)
{
    vis[node] = true;
    curr.push_back(node);

    for (ll i = 0; i < transpose[node].size(); i++)
    {
        ll next = transpose[node][i];

        if (!vis[next])
            dfs1(next);
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    ll n, m, i;
    cin >> n >> m;

    for (i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        transpose[v].push_back(u);
    }

    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }

    memset(vis, false, sz);

    reverse(order.begin(), order.end());

    for (i = 0; i < order.size(); i++)
    {
        if (!vis[order[i]])
        {
            dfs1(order[i]);
            scc.push_back(curr);
            curr.clear();
        }
    }

    cout << "Number of SCC : " << scc.size() << endl;

    for (i = 0; i < scc.size(); i++)
    {
        curr = scc[i];
        cout << "SCC No. " << i + 1 << ": ";

        for (ll j = 0; j < curr.size(); j++)
            cout << curr[j] << " ";
        cout << endl;
    }

    return 0;
}