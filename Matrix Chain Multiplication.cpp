
// time complexity : O(N*N*N)   N = Number of Elements

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, i, j;
    cin >> n;

    ll dim[n];
    ll dp[n][n];
    ll p[n][n];

    for (i = 0; i < n; i++)
        cin >> dim[i];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dp[i][j] = p[i][j] = 0;
        }
    }

    for (ll diff = 1; diff < n - 1; diff++)
    {
        for (i = 1; i < n - diff; i++)
        {
            j = i + diff;
            ll minn = 1e9;

            for (ll k = i; k < j; k++)
            {
                ll q = dp[i][k] + dp[k + 1][j] + dim[i - 1] * dim[k] * dim[j];

                if (q < minn)
                {
                    minn = q;
                    dp[i][j] = minn;
                    p[i][j] = k;
                }
            }
        }
    }



    cout << "Minimum Multiplication Needed : " << dp[1][n - 1] << endl;

    return 0;
}