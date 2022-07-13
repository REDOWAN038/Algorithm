
// time complexity : 0(V+E)  V = Vertex , E = Edge
// Tarjan algorithm is used to find Strongly Connected Component of a graph


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz 10000

vector <ll> graph[sz];
bool vis[sz];
bool inStack[sz];
ll in[sz];
ll low[sz];
stack <ll> st;
vector <ll> curr;
vector <vector<ll> > scc;
ll timer = 1;

void dfs(ll node)
{
    vis[node] = inStack[node] = true;
    in[node] = low[node] = timer++;
    st.push(node);

    for (ll i = 0; i < graph[node].size(); i++)
    {
        ll next = graph[node][i];

        if (vis[next] && inStack[next])
        {
            low[node] = min(low[node], in[next]);
        }

        else
        {
            if (vis[next])
                continue;

            dfs(next);

            if (inStack[next])
            {
                low[node] = min(low[node], low[next]);
            }
        }
    }

    if (in[node] == low[node])
    {
        curr.clear();

        while (1)
        {
            ll n = st.top();
            curr.push_back(n);
            st.pop();
            inStack[n] = false;
            if (node == n)
                break;
        }

        scc.push_back(curr);
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
    }

    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
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