
// time complexity : 0(N*W)   N = Number of Coins ; W = Amount
// Minimum Coin Needed to Make A Change


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

    ll n, amount, i, j;
    cin >> n >> amount;
    ll coin[n];
    ll dp[n + 1][amount + 1];

    for (i = 0; i < n; i++)
        cin >> coin[i];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= amount; j++)
        {
            if (i == 0)
                dp[i][j] = 1e9;
            else if (j == 0 && i != 0)
                dp[i][j] = 0;
            else if (j >= coin[i - 1])
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coin[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }


    cout << "Minimum Coin Needed : " << dp[n][amount] << endl;

    return 0;
}