
// time complexity : 0(NlogN)  N = number of elements


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

    ll n,  i;
    double capacity, totalProfit = 0.0;
    cin >> n >> capacity;
    vector <pair<double, double> >v;

    for (i = 0; i < n; i++)
    {
        double profit, weight;
        cin >> profit >> weight;
        double p = profit / weight;
        v.push_back({p, weight});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());


    for (i = 0; i < n && capacity; i++)
    {
        double curr = min(capacity, v[i].second);
        capacity -= curr;
        totalProfit += (curr * v[i].first);
    }

    cout << totalProfit << endl;

    return 0;
}