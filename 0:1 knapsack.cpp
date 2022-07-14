
// time complexity : 0(N*W)   N = Number of Elements ; W = Capacity


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

    ll n, capacity, i, j;
    cin >> n >> capacity;
    ll weight[n], profit[n];
    ll dp[n + 1][capacity + 1];

    for (i = 0; i < n; i++)
        cin >> weight[i];
    for (i = 0; i < n; i++)
        cin >> profit[i];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (j - weight[i - 1] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + profit[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }


    cout << "Maximum Profit : " << dp[n][capacity] << endl;

    return 0;
}