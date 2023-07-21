#include <iostream>
#include <string>
#define ll long long
using namespace std;

void solve()
{
	ll t, i;
	string s;
	int j, length;
	bool flag;
	do {
		cin >> t;
	} while (t < 1 || t > 10000);
	string *res = new string[t];
	for (i = 0; i < t; i++)
	{
		flag = false;
		cin >> s;
		length = s.length();
		for (j = 0; j < length; j++)
		{
			if (s[j] == 86 || s[j] == 90) flag = true;
		}		
		if (flag) res[i]="YES";  else res[i] ="NO";
	}
	for (i = 0; i < t; i++)
		cout << res[i] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
