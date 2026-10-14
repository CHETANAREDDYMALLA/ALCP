#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto pair : mp) {
        result.push_back(pair.second);
    }
    return result;
}
int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> grouped = groupAnagrams(strs);
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : grouped) {
        cout << "[ ";
        for (const string& s : group) {
            cout << s << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
