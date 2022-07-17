
// time complexity : O(NlogN)  : N = number of points


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
    float x, y;
};

vector <point> points;
vector <point> strip;

bool cmpx(point a, point b)
{
    return a.x <= b.x;
}

bool cmpy(point a, point b)
{
    return a.y <= b.y;
}

float dist(point p, point q)
{
    float v1 = (p.x - q.x) * (p.x - q.x);
    float v2 = (p.y - q.y) * (p.y - q.y);
    float val = sqrt(v1 + v2);
    return val;
}

float getMinDist(ll l, ll r)
{
    float minn = 1e9;

    for (ll i = l; i < r; i++)
    {
        for (ll j = i + 1; j < r; j++)
        {
            if (dist(points[i], points[j]) < minn)
                minn = dist(points[i], points[j]);
        }
    }

    return minn;
}

float getStripMinimum(float d)
{
    float minn = d;
    sort(strip.begin(), strip.end(), cmpy);


    for (ll i = 0; i < strip.size(); i++)
    {
        for (ll j = i + 1; j < strip.size() && strip[j].y - strip[i].y < minn; j++)
        {
            if (dist(strip[j], strip[i]) < minn)
                minn = dist(strip[j], strip[i]);
        }
    }

    return minn;
}

float getMinimum(ll l, ll r)
{
    ll n = r - l;

    if (n <= 3)
        return getMinDist(l, r);

    ll mid = n / 2;
    point midPoint = points[mid];

    float dl = getMinimum(l, mid - 1);
    float dr = getMinimum(mid + 1, r);

    float d = min(dl, dr);

    for (ll i = 0; i < n; i++)
    {
        if (points[i].x - midPoint.x < d)
            strip.push_back(points[i]);
    }

    return min(d, getStripMinimum(d));
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

    sort(points.begin(), points.end(), cmpx);

    float res = getMinimum(0, n);

    cout << "Minimum Distance : " << res << endl;

    return 0;
}