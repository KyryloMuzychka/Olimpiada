#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#include <fstream>
#include <thread>
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define all(v) v.begin(), v.end()

using namespace std;

void CalculateAmountForTakingOff(ll start, ll end, ll pos, deque<pii> circles, ll &amount) {
    amount = 0;
     for (ll i = start; i < end; i++) {
        if (circles[pos].first < circles[i].second) {
            amount++;
        }
    }
}

void Solve() {
    
    ifstream input;
    input.open("input.txt");
    if (input.is_open()) {
        
        ofstream output("output.txt");
        deque<pii> circles;
        ll number, count = 0, m, innerDiameter, externalDiameter, leftSide, rightSide;
        
        while (input >> number) {
            if (!count) {
                innerDiameter = number;
                count++;
            } else {
                externalDiameter = number;
                circles.push_back(make_pair(innerDiameter, externalDiameter));
                count = 0;
            }
        }

        m = circles[0].second;
        circles.pop_front();
        
        thread th1(CalculateAmountForTakingOff, 0, m-1, m-1, circles, std::ref(leftSide));
        thread th2(CalculateAmountForTakingOff, m, circles.size(), m-1, circles, std::ref(rightSide));
        th1.join();
        th2.join();
        
        if (leftSide < rightSide) output << leftSide;
        else output << rightSide;;
        
    }
    else {
        cout << "File is not open\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solve();
    return 0;
}
