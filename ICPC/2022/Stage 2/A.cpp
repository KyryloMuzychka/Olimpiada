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
void solve()
{
	ll n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(all(a), greater<ll>());
	for (int i = 0; i < n; ++i)
		if (i % 2)
			r.push_front(a[i]);
		else r.push_back(a[i]);
	ll sum = 0;
	for (int i = 1; i < n; ++i)
		sum += r[i - 1] * r[i];
	sum += r[n - 1] * r[0];
	cout << sum << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
