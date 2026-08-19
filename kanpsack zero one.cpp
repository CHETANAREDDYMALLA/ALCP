#include <iostream>
using namespace std;
int knapsack(int capacity, int wt[], int value[], int n) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - wt[i - 1]],
                                dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][capacity];
}
int main() {
    int capacity, n;
    cout << "Enter the no of items: ";
    cin >> n;
    int wt[n], value[n];
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];
    cout << "Enter capacity: ";
    cin >> capacity;
    cout << "Maximum value = " << knapsack(capacity, wt, value, n);
    return 0;
}
