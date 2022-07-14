
// time complexity : 0(N*M)   N = Size of First String ; M = Size of Second String
// Minimum Edit Distance minimum operation needed to change a string to another string
// here operations are : insertion,deletion,replace


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

    string s, t;
    cin >> s >> t;
    ll i, j;
    ll n = s.size();
    ll m = t.size();
    ll dp[m + 1][n + 1];

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s[j - 1] == t[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    }


    cout << "Edit Distance : " << dp[m][n] << endl;

    return 0;
}