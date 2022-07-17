
// time complexity : O(NlogN)  : N = number of points
// graham scan algo is used to get the convex polygon points


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
    ll x, y;
};

vector <point> points;
stack <point> s;

ll orientation(point p, point q, point r)
{
    ll v1 = (q.y - p.y) * (r.x - q.x);
    ll v2 = (q.x - p.x) * (r.y - q.y);
    ll val = v1 - v2;
    return val;
}

ll dist(point p, point q)
{
    ll v1 = (p.x - q.x) * (p.x - q.x);
    ll v2 = (p.y - q.y) * (p.y - q.y);
    return v1 + v2;
}

bool cmp(point p, point q)
{
    ll o = orientation(s.top(), p, q);

    if (o == 0)
        return dist(s.top(), q) >= dist(s.top(), p);
    else
        return o < 0;
}

point nexttoTop()
{
    point p = s.top();
    s.pop();
    point q = s.top();
    s.push(p);
    return q;
}

void convexHull(ll n)
{
    ll miny = points[0].y;
    ll idx = 0;

    for (ll i = 1; i < n; i++)
    {
        if (points[i].y < miny)
        {
            miny = points[i].y;
            idx = i;
        }

        else if (points[i].y == miny && points[i].x < points[idx].x)
        {
            idx = i;
        }
    }

    s.push(points[idx]);

    for (auto it = points.begin(); it != points.end(); it++)
    {
        point a = *it;

        if (a.x == points[idx].x && a.y == points[idx].y)
        {
            points.erase(it);
            break;
        }
    }

    sort(points.begin(), points.end(), cmp);

    // for (ll i = 0; i < points.size(); i++)
    //     cout << points[i].x << " " << points[i].y << endl;

    s.push(points[0]);
    s.push(points[1]);

    for (ll i = 2; i < points.size(); i++)
    {
        while (s.size() > 1 && orientation(nexttoTop(), s.top(), points[i]) > 0)
        {
            s.pop();
        }

        s.push(points[i]);
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

    while (s.size())
    {
        point a = s.top();
        s.pop();
        cout << a.x << " " << a.y << endl;
    }

    return 0;
}