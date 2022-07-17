
// time complexity : O(1)
// we can found whether two lines intersect or not


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
    ll x, y;
};

point p1, q1, p2, q2;

ll orientation(point p, point q, point r)
{
    ll v1 = (q.y - p.y) * (r.x - q.x);
    ll v2 = (q.x - p.x) * (r.y - q.y);
    ll val = v1 - v2;
    return val;
}

bool onSegment(point p, point q, point r)
{
    ll maxx = max(p.x, r.x);
    ll minx = min(p.x, r.x);
    ll maxy = max(p.y, r.y);
    ll miny = min(p.y, r.y);

    if ((q.x >= minx && q.x <= maxx) && (q.y >= miny && q.y <= maxy))
        return true;
    else
        return false;
}

bool doIntersect()
{
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    else if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    else if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    else if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    else if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> p1.x >> p1.y;
    cin >> q1.x >> q1.y;
    cin >> p2.x >> p2.y;
    cin >> q2.x >> q2.y;

    cout << "Inersection Happen : ";
    if (doIntersect())
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}