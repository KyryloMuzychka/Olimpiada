#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <iomanip>
#include <algorithm>
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define all(v) v.begin(), v.end()

using namespace std;

void Solve() {
    ll N, M, S, A, B, amount = 0;    
    deque<pair<ll, ll>> cost;
    vi dif;
    cin >> N >> M >> S;
    ll t = N;
    while (t--) {
        cin >> A >> B;
        cost.push_back(make_pair(A, B));        
    }

    sort(all(cost), [](const pii& pair1, const pii& pair2) {
        return pair1.second < pair2.second;
        });

    ll dronesBought = 0;
    for (ll i = 0; i < N; i++) {
        if (M) {            
            if (cost[i].second <= S) {
                S -= cost[i].second;
                M--;
                dronesBought++;
            }
        }
        else {
            
            if (cost[i].first <= S) {
                S -= cost[i].first;
                dronesBought++;
            }
        }
        
    }

    cout << dronesBought;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}