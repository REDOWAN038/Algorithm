
// time complexity : 0(ElogV)  V = Vertex , E = Edge
// Kruskal algo is used to get the minimum weight of a spanning tree


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz 10000

struct edge {
    ll a, b, w;
} graph[sz];

ll par[sz];
ll rnk[sz];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

ll findParent(ll n)
{
    if (n == par[n])
        return n;
    return findParent(par[n]);
}

void merge(ll u, ll v)
{
    if (rnk[u] > rnk[v])
    {
        par[v] = u;
        rnk[u] += rnk[v];
    }

    else
    {
        par[u] = v;
        rnk[v] += rnk[u];
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

    ll n, m, i, sum = 0;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
    {
        par[i] = i;
        rnk[i] = 1;
    }

    for (i = 0; i < m; i++)
    {
        cin >> graph[i].a >> graph[i].b >> graph[i].w;
    }

    sort(graph, graph + m, cmp);

    for (i = 0; i < m; i++)
    {
        ll u = findParent(graph[i].a);
        ll v = findParent(graph[i].b);

        if (u == v)
            continue;
        else
        {
            merge(u, v);
            sum += graph[i].w;
        }
    }

    cout << "Minimum Weight : " << sum << endl;

    return 0;
}