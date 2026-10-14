#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    int weight;
    int value;
};
struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
float bound(Node u, int n, int W, const vector<Item>& arr) {
    if (u.weight >= W)
        return 0;
    float profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while ((j < n) && (totweight + arr[j].weight <= W)) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    if (j < n)
        profit_bound += (W - totweight) * ((float)arr[j].value / arr[j].weight);
    return profit_bound;
}
int knapsack(int W, vector<Item>& arr, int n) {
    sort(arr.begin(), arr.end(), cmp);
    vector<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    Q.push_back(u);
    int maxProfit = 0;
    while (!Q.empty()) {
        u = Q.back();
        Q.pop_back();
        if (u.level == -1)
            v.level = 0;
        if (u.level == n - 1)
            continue;
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push_back(v);
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push_back(v);
    }
    return maxProfit;
}
int main() {
    int W = 50;
    vector<Item> arr = {{10, 60}, {20, 100}, {30, 120}};
    int n = arr.size();
    cout << "Maximum Profit: " << knapsack(W, arr, n) << endl;
    return 0;
}
