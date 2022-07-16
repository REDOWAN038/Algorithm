
// time complexity : O(V*E^2)   V = Number of Vertices ; E = Number of Edges
// we can also get maximum bipartite matching using this

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz 1000

ll graph[sz][sz];
ll residualGraph[sz][sz];
bool vis[sz];
ll par[sz];
ll n, m;

ll bfs(ll s, ll t)
{
    memset(vis, false, sz);
    queue <ll> q;
    q.push(s);
    vis[s] = true;
    par[s] = -1;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        for (ll v = 0; v < n; v++)
        {
            if (!vis[v] && residualGraph[u][v] > 0)
            {
                if (v == t)
                {
                    par[v] = u;
                    return true;
                }

                q.push(v);
                par[v] = u;
                vis[v] = true;
            }
        }
    }

    return false;
}

ll fordFulkerson(ll s, ll t)
{
    ll maxFlow = 0;

    while (bfs(s, t))
    {
        ll bottleneckCapacity = 1e18;

        for (ll v = t; v != s; v = par[v])
        {
            ll u = par[v];
            bottleneckCapacity = min(bottleneckCapacity, residualGraph[u][v]);
        }

        for (ll v = t; v != s; v = par[v])
        {
            ll u = par[v];
            residualGraph[u][v] -= bottleneckCapacity;
            residualGraph[v][u] += bottleneckCapacity;
        }

        maxFlow += bottleneckCapacity;
    }

    return maxFlow;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i;
    cin >> n >> m;

    for (i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = residualGraph[u][v] = w;
    }

    ll src, sink;
    cin >> src >> sink;

    ll res = fordFulkerson(src, sink);

    cout << "Maximum Flow from " << src << " to " << sink << " : " << res << endl;

    return 0;
}