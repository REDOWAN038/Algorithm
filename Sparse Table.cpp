
// time complexity : Create : O(NlogN)  : N = number of elements
//                   Query  : O(1)


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz 100000
ll logs[sz + 5];

void pre()
{
    logs[1] = 0;

    for (ll i = 2; i <= sz; i++)
        logs[i] = logs[i / 2] + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre();

    ll n, i, q, j;
    cin >> n;
    ll a[n];

    for (i = 0; i < n; i++)
        cin >> a[i];

    ll k = logs[n];

    ll st[n + 1][k + 1];

    for (i = 0; i < n; i++)
        st[i][0] = a[i];

    for (j = 1; j <= k; j++)
    {
        for (i = 0; (i + (1 << j)) <= n; i++)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    cin >> q;

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll len = (r - l + 1);
        ll p = logs[len];
        ll ans = min(st[l][p], st[r - (1 << p) + 1][p]);
        cout << ans << endl;
    }

    return 0;
}
