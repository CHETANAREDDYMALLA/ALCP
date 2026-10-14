#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Activity {
    int start;
    int finish;
};
bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}
void printMaxActivities(vector<Activity>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end(), compareActivities);
    cout << "Selected Activities (Start, Finish):" << endl;
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")" << endl;
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")" << endl;
            i = j;
        }
    }
}
int main() {
    vector<Activity> arr = {
        {1, 3},
        {2, 5},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };
    printMaxActivities(arr);
    return 0;
}
