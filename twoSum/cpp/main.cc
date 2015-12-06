#include "solution.h"

int main() {
    string filePath = "testData/case1";
    vector<int> nums;
    vector<int> ret;
    vector<int> ans;
    int target;
//    int n[5] = {1, 2, 3, 4, 5};
//    for (int i = 0; i < 5; i++)  nums.insert(nums.begin(), n[i]);

    readFile(filePath, nums, target, ans);
    Solution *obj = new Solution();
    ret = obj->twoSum(nums, target);


    for (auto it = ret.begin(); it != ret.end(); it++) {
        cout << "ret = " << *it << endl;
    }
    return 0;
}
