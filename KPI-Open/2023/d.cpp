#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define all(v) v.begin(), v.end()

using namespace std;

struct Point {
    ll x, y;
};


int countIntegerPoints(const std::vector<Point>& points) {
    std::unordered_set<int> uniquePoints;

    for (const auto& point : points) {
        uniquePoints.insert(point.x * 100000 + point.y);
    }

    return uniquePoints.size();
}

void Solve() {
    ll n;
    cin >> n;

    vector<Point> points;
    for (ll i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {
            ll min_y = min(y1, y2);
            ll max_y = max(y1, y2);
            for (ll y = min_y; y <= max_y; y++) {
                points.push_back({ x1, y });
            }
        }
        else if (y1 == y2) {
            ll min_x = min(x1, x2);
            ll max_x = max(x1, x2);
            for (ll x = min_x; x <= max_x; x++) {
                points.push_back({ x, y1 });
            }
        }
        else {
            ll min_x = min(x1, x2);
            ll max_x = max(x1, x2);
            ll min_y = min(y1, y2);
            ll max_y = max(y1, y2);

            for (ll x = min_x; x <= max_x; x++) {
                double y = (((double)(y2 - y1) * (x - x1)) / (x2 - x1)) + y1;
                if (floor(y) == y) {
                    points.push_back({ x, (ll)y });
                }
            }
        }
    }

    cout << countIntegerPoints(points);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}