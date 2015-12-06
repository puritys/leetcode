#include "solution.h"

vector<int> SolutionSimple::twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    for (auto n = nums.begin(); n != nums.end(); n++) {
        int remain = target - *n;
        auto found = find(nums.begin(), nums.end(), remain);
        if (found != nums.end()) {
            if (remain < *n) {
                swap(remain, *n);
            }

            ret.insert(ret.begin(), remain);
            ret.insert(ret.begin(), *n);
            return ret;
        }
    }
    return ret;
}

