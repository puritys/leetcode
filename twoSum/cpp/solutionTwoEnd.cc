#include "solution.h"

vector<int> SolutionTwoEnd::twoSum(vector<int>& nums, int target) {
    vector<int> copy;
    vector<int> ret;
    int sum;
    copy = nums;
    sort(copy.begin(), copy.end());
    vector<int>::iterator num1, num2;
    for (num1 = copy.begin(), num2 = copy.end() - 1 ; num1 != copy.end(), num2 != copy.end(); ) {
        sum = *num1 + *num2;
        if (sum < target) {
            num1++;
        } else if (sum > target) {
            num2--;
        } else {
            int index1 = find(nums.begin(), nums.end(), *num1) - nums.begin() + 1;
            int index2 = find(nums.begin(), nums.end(), *num2) - nums.begin() + 1;
            if (index1 == index2) index2 = find(nums.begin() + index1, nums.end(), *num2) - nums.begin() + 1;
            if (index1 > index2) swap(index1, index2);
            return {index1, index2};
        }
    }

    return ret;
}
