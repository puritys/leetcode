#include "solution.h"

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    vector<int> copy;
    int num1, num2;
    copy = nums;
    sort(copy.begin(), copy.end());
    for (auto n = copy.begin(); n != copy.end(); n++) {
        num2 = target - *n;
        auto found = find(copy.begin(), copy.end(), num2);
        if (found != copy.end()) {
            num1 = *n; 
            break;
        }
    }

    int index1 = find(nums.begin(), nums.end(), num1) - nums.begin() + 1;
    int index2 = find(nums.begin(), nums.end(), num2) - nums.begin() + 1;
    if (index1 == index2) index2 = find(nums.begin() + index1, nums.end(), num2) - nums.begin() + 1;
    if (index1 > index2) swap(index1, index2);
    return {index1, index2};
}


void readFile(string filePath, vector<int> &inputs, int &target, vector<int> &ans) {
    FILE *f = fopen(filePath.c_str(), "r");
    int n;
    fscanf(f, "%d", &n);
    inputs.insert(inputs.begin(), n);

    while (1) {
        if (fscanf(f, ",%d", &n)) {
            inputs.insert(inputs.end(), n);
        } else {
            break;
        }
    }

    if (fscanf(f, "\n%d", &n)) {
        target = n;
    }
    int ans1, ans2;
    if (fscanf(f, "\n%d,%d", &ans1, &ans2)) {
        ans.insert(ans.begin(), ans2);
        ans.insert(ans.begin(), ans1);
    }

}

