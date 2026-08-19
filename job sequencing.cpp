#include <iostream>
#include <algorithm>
using namespace std;
struct Job {
    char id;
    int deadline;
    int profit;
};
bool compare(Job a,Job b) {
    return a.profit>b.profit;
}
int main() {
    int n;
    cout<<"Enter number of jobs: ";
    cin>>n;
    Job jobs[n];
    cout<<"Enter job id, deadline and profit:\n";
    for(int i=0;i<n;i++) {
        cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
    }
    sort(jobs,jobs+n,compare);
    int maxDeadline=0;
    for (int i=0;i<n;i++)
        maxDeadline=max(maxDeadline,jobs[i].deadline);
    char slot[maxDeadline];
    bool filled[maxDeadline]={false};
    int totalProfit=0;
    for (int i=0;i<n;i++) {
        for(int j=jobs[i].deadline-1;j>=0;j--) {
            if(!filled[j]) {
                slot[j]=jobs[i].id;
                filled[j]=true;
                totalProfit+=jobs[i].profit;
                break;
            }
        }
    }
    cout<< "\nSelected jobs: ";
    for (int i=0;i<maxDeadline;i++) {
        if(filled[i])
            cout<<slot[i]<< " ";
    }
    cout<< "\nMaximum Profit = " <<totalProfit;
    return 0;
}
