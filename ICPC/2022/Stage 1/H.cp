#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool if_even_sample(vector<int> list)
{
	if (list.size() % 2 == 0)
		return false;

	bool isSample = true;

	for (int i = 1; i < list.size(); i++)
	{
		if (list[i - 1] != list[i])
			isSample = false;
	}

	return isSample;
}

void print_vec(vector<int> vec) 
{
	for (int j = 0; j < vec.size(); j++)
	{
		cout << vec[j] << " ";
	}
}

int replace_color(int base_i, int prev_res)
{
	int n;
	if (base_i == 1)
	{
		n = 2;
		if (n == prev_res)
			n = 3;
	}
	else if (base_i == 2)
	{
		n = 1;
		if (n == prev_res)
			n = 3;
	}
	else
	{
		n = 2;
		if (n == prev_res)
			n = 1;
	}
	return n;
}
int replace_color2(int res_i, int prev_res,int base_i)
{
	int n;
	if (res_i == 1)
	{
		n = 3;
		if (n == prev_res || n == base_i)
			n = 2;
	    
	}
	else if (res_i == 2)
	{
		n = 3;
		if (n == prev_res || n == base_i)
			n = 1;
	}
	else
	{
		n = 1;
		if (n == prev_res || n == base_i)
			n = 2;
	}
	return n;
}

int check_first(int base_first, int rez_first, int rez_last)
{
	int nn = rez_first;

	if (rez_first == rez_last) {
		if (base_first == 1 || base_first == 2) {
			nn = 3;
		}
		else {
			nn = 1;
		}
	}
	return nn;
}

vector<int> redraw(vector<int> list)
{
	vector<int> result;

	for (int i = 0; i < list.size(); i++)
	{
		if (i == 0) result.push_back(replace_color(list[0], 0));

		else result.push_back(replace_color(list[i], result[i - 1]));

		if (i == list.size() - 1) 
		{
			result[0] = check_first(list[0], result[0], result[list.size() - 1]);
		}
	}
	for (int j = 1; j < list.size(); j++)
	{
		if (result[j - 1] == result[j])
		{
			result[j] = replace_color2(result[j - 1], result[j], list[j]);
		}
	}
		
	return result;
}

void solve()
{
	vector<int>* lists;
	vector<int>* rez;

	int m, n, p;
	cin >> m;

	lists = new vector<int>[m];
	rez = new vector<int>[m];

	for (int i = 0; i < m; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> p;
			lists[i].push_back(p);
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (if_even_sample(lists[i])) cout << "\nNO";
		else
		{
			cout << "\nYES\n";
			rez[i] = redraw(lists[i]);
			print_vec(rez[i]);
		}
	}
}

int main() {

	solve();

	system("pause");

	return 0;
}