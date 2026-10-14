#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;
    for (int num : numSet) {
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}
int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = longestConsecutive(nums);
    cout << "Longest Consecutive Sequence Length: " << result << endl;
    return 0;
}
