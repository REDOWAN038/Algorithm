
// time complexity : O(N*H)  : N = number of points ; H = hull size
// jarvis march algo is used to get the convex polygon points


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
    ll x, y;
};

vector <point> points;
vector <point> hull;

ll orientation(point p, point q, point r)
{
    ll v1 = (q.y - p.y) * (r.x - q.x);
    ll v2 = (q.x - p.x) * (r.y - q.y);
    ll val = v1 - v2;
    return val;
}

void convexHull(ll n)
{
    if (n < 3)
        return;

    ll idx = 0;

    for (ll i = 1; i < n; i++)
    {
        if (points[i].x < points[idx].x)
        {
            idx = i;
        }
    }

    ll p = idx;

    do {
        hull.push_back(points[p]);
        ll q = (p + 1) % n;

        for (ll i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) < 0)
                q = i;
        }

        p = q;
    } while (p != idx);

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, i;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        point a;
        cin >> a.x >> a.y;
        points.push_back(a);
    }

    convexHull(n);

    cout << "Convex Hull Points are : \n";

    for (ll i = 0; i < hull.size(); i++)
        cout << hull[i].x << " " << hull[i].y << endl;

    return 0;
}