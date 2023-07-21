#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define all(v) v.begin(), v.end()

using namespace std;

void Solve(ll i) {
    ll number;
    vi data;
    ifstream input;
    input.open("input" + to_string(i) + ".txt");    
    if (input.is_open()) {
        ofstream output("output" + to_string(i) + ".txt");
        while (input >> number) {
            data.push_back(number);
        }
        output << (ll)pow((ll)(pow(data[0],data[1])) % data[3], data[2] - 1) % data[3] << endl;
    }
    else {
        cout << "File is not open\n";
    }
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    while (n)
        Solve(n--);
    return 0;
}