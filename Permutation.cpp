
// time complexity : O(nPr)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz 1000

bool vis[sz];
vector <ll> v;

void print()
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void permute(ll n, ll r)
{
    if (v.size() == r)
    {
        print();
        return;
    }

    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            v.push_back(i);
            vis[i] = true;

            permute(n, r);

            v.pop_back();
            vis[i] = false;
        }
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

    ll n, r;
    cin >> n >> r;
    permute(n, r);

    return 0;
}