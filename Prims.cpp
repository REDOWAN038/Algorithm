
// time complexity : 0(V^2)  V = Vertex , E = Edge
// Prims algo is used to get the minimum weight of a spanning tree


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz 10000

ll graph[sz][sz];
bool vis[sz];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, i, j, sum = 0;
    cin >> n >> m;

    for (i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    vis[1] = true;
    ll edges = 0;

    cout << "Edges are : \n";

    while (edges < n - 1)
    {
        ll x = -1;
        ll y = -1;
        ll minn = 1e9;

        for (i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                for (j = 1; j <= n; j++)
                {
                    if (!vis[j] && graph[i][j] && graph[i][j] < minn)
                    {
                        minn = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " " << y << endl;
        sum += minn;
        vis[y] = true;
        edges++;
    }

    cout << "Minimum Weight : " << sum << endl;

    return 0;
}