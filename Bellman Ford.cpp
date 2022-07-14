
// time complexity : 0(V*E)  V = Vertex ; E = Edges
// BellMan Ford algo is used to calculate shortest distance when negative edge value is present
// it can't work in negative weight cycle


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz 10000

struct edges {
    ll a, b, w;
} graph[sz];

ll dist[sz];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, i, j, src, dest;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
        dist[i] = 1e9;

    for (i = 0; i < m; i++)
    {
        cin >> graph[i].a >> graph[i].b >> graph[i].w;
    }

    cin >> src >> dest;

    dist[src] = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            dist[graph[j].b] = min(dist[graph[j].b], dist[graph[j].a] + graph[j].w);
        }
    }

    bool ok = false;

    for (j = 0; j < m; j++)
    {
        if (dist[graph[j].b] > dist[graph[j].a] + graph[j].w)
        {
            ok = true;
            break;
        }
    }

    if (ok)
        cout << "Negative Weight Cycle Exist\n";
    else
        cout << "Shortest Distance from " << src << " to " << dest << " : " << dist[dest] << endl;

    return 0;
}