#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
struct Item {
    double weight, value;
};
bool compare(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}
double fractionalKnapsack(vector<Item>& A, double Total_capacity) {
    int n = A.size();
    sort(A.begin(), A.end(), compare);
    double curr_weight = 0.0;
    double final_value = 0.0;
    for (int i = 0; i < n; i++) {
        if (curr_weight + A[i].weight <= Total_capacity) {
            curr_weight += A[i].weight;
            final_value += A[i].value;
        } 
        else {
            double remain = Total_capacity - curr_weight;
            final_value += A[i].value * (remain / A[i].weight);
            break; 
        }
    }
    return final_value;
}
int main() {
    int n;
    double capacity;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> A(n);
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i].weight >> A[i].value;
    }
    cout << "Enter capacity: ";
    cin >> capacity;
    cout << "Max value: " << fractionalKnapsack(A, capacity) << endl;
    return 0;
}
