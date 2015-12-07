#include "solution.h"

vector<vector<int>> SolutionVersion1::threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    auto num2 = nums.begin();
    auto num3 = nums.end() - 1;
    for (auto num1 = nums.begin(); num1 != nums.end(); num1++) {
        if (*num1 > 0) continue;
        //Compare the result of start index + end index with number 1
        for (num2 = num1 + 1, num3 = nums.end() - 1; num2 != nums.end() && num3 > num2;) {
            //cout << "sum = " << *num1 << " " << *num2 << " " << *num3 << endl;
            int sum = *num1 + *num2 + *num3;
            if (sum < 0) {
                num2++;
            } else if (sum > 0) {
                num3--;
            } else {
                ret.insert(ret.end(), {*num1, *num2, *num3});
                // skip the same number
                while ((num1 + 1) != nums.end() && *num1 == *(num1 + 1)) num1++;
                while ((num2 + 1) != nums.end() && *num2 == *(num2 + 1)) num2++;
                while ((num3 - 1) != num2 && *num3 == *(num3 - 1)) num3--;
                num2++;
            }
        }
    }
    return ret;

}
