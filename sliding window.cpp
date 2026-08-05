#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> slidingWindowMax(vector<int> &arr, int k) {
    deque<int> dq;
    vector<int> result;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cout << "Enter window size k: ";
    cin >> k;
    vector<int> result = slidingWindowMax(arr, k);
    cout << "Sliding window maximums: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
