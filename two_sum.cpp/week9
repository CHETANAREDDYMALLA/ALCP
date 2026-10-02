#include <bits/stdc++.h>
using namespace std;
vector<int> twosum(vector<int>&arr,int target){
    unordered_map<int,int>map;
    for (int i=0;i<arr.size();i++){
        int complement =target-arr[i];
        if(map.find(complement)!=map.end()){
            return {map[complement],i};
        }
        map[arr[i]]=i;
    }
    return {};
}
int main()
{
    int n,i;
    cout<<"enter number of elements:";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter"<<n<<"elements:";
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
    int target,sum;
    cout<<"enter target sum:";
    cin>>target;
    vector<int>result=twosum(arr,sum);
    if (result.empty()){
        cout<<"no valid pair found"<<endl;
    } else{
        cout<<"indices:"<<result[0]<<","<<result[i]<< endl;
    }
    return 0;
}
