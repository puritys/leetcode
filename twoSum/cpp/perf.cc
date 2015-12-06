#include "solution.h"
#include "smartPerf.h"

void test1(string filePath) {
    vector<int> nums;
    vector<int> ret;
    vector<int> ans;
    int target;

    readFile(filePath, nums, target, ans);
    SolutionSimple *obj = new SolutionSimple();
    ret = obj->twoSum(nums, target);
}

void test2(string filePath) {
    vector<int> nums;
    vector<int> ret;
    vector<int> ans;
    int target;

    readFile(filePath, nums, target, ans);
    Solution *obj = new Solution();
    ret = obj->twoSum(nums, target);
}

void testTwoEnd(string filePath) {
    vector<int> nums;
    vector<int> ret;
    vector<int> ans;
    int target;

    readFile(filePath, nums, target, ans);
    Solution *obj = new Solution();
    ret = obj->twoSum(nums, target);
}
int main () {
    int max = 1;
    string filePath = "testData/case1";

    smartPerf::start("test1");
    for (int i = 0; i < max; i++) test1(filePath);
    smartPerf::end();

    smartPerf::start("test2");
    for (int i = 0; i < max; i++) test2(filePath);
    smartPerf::end();

    smartPerf::start("testTwoEnd");
    for (int i = 0; i < max; i++) testTwoEnd(filePath);
    smartPerf::end();


    smartPerf::print();

    return 0;
}
