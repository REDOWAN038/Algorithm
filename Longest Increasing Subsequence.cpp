
// time complexity : O(N*N)   N = Number of Elements

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
    ll a[n], dp[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    ll res = dp[0];

    for (i = 1; i < n; i++)
        res = max(res, dp[i]);

    cout << "Lenght of Longest Increasing Subsequence : " << res << endl;

    return 0;
}