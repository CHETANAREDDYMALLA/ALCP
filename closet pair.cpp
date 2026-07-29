#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>
using namespace std;
struct Point {
    int x, y;
};
double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}
double bruteForce(vector<Point>& P, int l, int r) {
    double minDist = DBL_MAX;
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            minDist = min(minDist, dist(P[i], P[j]));
        }
    }
    return minDist;
}
bool cmpX(Point a, Point b) {
    return a.x < b.x;
}
bool cmpY(Point a, Point b) {
    return a.y < b.y;
}
double stripClosest(vector<Point>& strip, double d) {
    sort(strip.begin(), strip.end(), cmpY);
    double minDist = d;
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() &&
             (strip[j].y - strip[i].y) < minDist; j++) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}
double closestUtil(vector<Point>& P, int l, int r) {
    if (r - l <= 2)
        return bruteForce(P, l, r);
    int mid = (l + r) / 2;
    Point midPoint = P[mid];
    double dl = closestUtil(P, l, mid);
    double dr = closestUtil(P, mid + 1, r);
    double d = min(dl, dr);
    vector<Point> strip;
    for (int i = l; i <= r; i++) {
        if (abs(P[i].x - midPoint.x) < d)
            strip.push_back(P[i]);
    }
    return min(d, stripClosest(strip, d));
}
double closest(vector<Point>& P) {
    sort(P.begin(), P.end(), cmpX);
    return closestUtil(P, 0, P.size() - 1);
}
int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    vector<Point> P(n);
    cout << "Enter x and y coordinates:\n";
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }
    cout << "\nMinimum distance = " << closest(P) << endl;
    return 0;
}
