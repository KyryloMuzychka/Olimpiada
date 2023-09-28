#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#define ll long long
#define vi vector<ll>
#define pii pair<ll,ll>
#define all(v) v.begin(),v.end()

using namespace std;

vi res;

void solve()
{
    ll n,q;
    ll type, x;
    
    cin >> n >> q;
    
    vi arr(n);
    for (ll i = 0; i < arr.size(); i++)
        cin >> arr[i];
  
    sort(arr.begin(), arr.end(), greater<>());
    
    ll change = 0;
    
    for (ll index = 0; index < q; index++)
    {
        cin >> type >> x;
        
        if (type == 1)
        {
            change += x;
        }
        else
        {
            res.push_back(arr[x-1] + change);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    for (auto it : res)
    {
        cout << it << endl;
    }
    
    
    
    return 0;
}

