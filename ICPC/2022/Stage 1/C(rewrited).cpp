#include <bits/stdc++.h>
#define ll long long
using namespace std;
double calcDistance(pair<ll,ll> a,pair<ll,ll> b)
{
	return sqrt(pow(a.first - b.first,2) + pow(a.second - b.second,2));
}
void solve()
{
	ll n;
	cin>>n;
	vector<pair<ll,ll>> xa,ya;
	map<pair<ll,ll>,int> indexes;
	for(ll i=0;i<n;++i)
	{
		ll x,y;
		cin>>x>>y;

		indexes[make_pair(x,y)]=i;

		if(x==0)
			ya.push_back(make_pair(x,y));
		else
			xa.push_back(make_pair(x,y));
	}
	sort(xa.begin(),xa.end());
	sort(ya.begin(),ya.end(),[] (auto a,auto b){
				if(a.second < b.second)
					return true;
				return false;
				});
	
	ll mix=1e10;
	ll miy=1e10;

	for(ll i=0;i<xa.size();++i)
			mix=min(mix,abs(xa[i].first));

	for(ll i=0;i<ya.size();++i)
			miy=min(miy,abs(ya[i].second));

	pair<ll,ll> min_xp,min_yp;
	min_xp = make_pair(mix,0); // nearest point to (0,0) from X axis;
	min_yp = make_pair(0,miy); // nearest point to (0,0) from Y axis;
	vector<pair<int,double>> result;

	
	double mi1,mi2,mi3;
	double mi12;
	for(ll i=0;i<xa.size();++i)
	{
		if(i==0)
			mi1=1e10;
		else
			mi1=calcDistance(xa[i], xa[i-1]);
		if(i==xa.size()-1)
			mi2=1e10;
		else
			mi2=calcDistance(xa[i], xa[i+1]);

		mi12 = min(mi1,mi2);
		mi3=calcDistance(xa[i], min_yp);
		mi12 = min(mi12,mi3);

		int index=indexes[xa[i]];
		result.push_back(make_pair(index,mi12));
	}
	for(ll i=0;i<ya.size();++i)
	{
		if(i==0)
			mi1=1e10;
		else
			mi1=calcDistance(ya[i],ya[i-1]);;
		if(i==ya.size()-1)
			mi2=1e10;
		else
			mi2=calcDistance(ya[i],ya[i+1]);

		mi12=min(mi1,mi2);
		mi3= calcDistance(ya[i],min_xp);
		mi12 = min(mi12,mi3);

		int index=indexes[ya[i]];
		result.push_back(make_pair(index,mi12));
	}

	sort(result.begin(),result.end());

	cout<<fixed;
	cout<<setprecision(6);
	for(auto &el:result)
		cout<<el.second<<" ";
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--){
	solve();
	}
	return 0;
}
