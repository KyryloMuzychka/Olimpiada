#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cmath>
#include <deque>
#include <queue>
#include <climits>
#define ll long long
#define vi vector<ll>
#define pii pair<ll,ll>
#define all(v) v.begin(),v.end()

using namespace std;

void solve()
{
	ll n, minOperations = LLONG_MAX, flag=0;
	cin >> n;

	vi arr(n);
	vi arrayForMinOperations;
	
	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];		
	}

	for (ll i = 1; i < n; i++)
	{		
		if (arr[i] > arr[i-1])
		{ 
			minOperations = min(arr[i] - arr[i - 1], minOperations);	
		}
		else
		{
			flag = 1;
			break;
		}
	}

	cout << (flag ? 0 : minOperations) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}