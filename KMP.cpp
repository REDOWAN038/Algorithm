
// time complexity : O(N+M)   :  N = size of text ; M = size of pattern


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> getLPS(string pattern)
{
    ll n = pattern.size();
    vector <ll> lps(n);
    lps[0] = 0;
    ll j = 0;
    ll i = 1;

    while (i < n)
    {
        if (pattern[i] == pattern[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }

        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void findMatch(string text, string pattern)
{
    vector <ll> lps = getLPS(pattern);

    // for (ll i = 0; i < lps. size(); i++)
    //     cout << lps[i] << " ";

    ll n = text.size();
    ll m = pattern.size();

    ll i = 0;
    ll j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }

        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
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

    string text, pattern;
    cin >> text >> pattern;

    findMatch(text, pattern);

    return 0;
}