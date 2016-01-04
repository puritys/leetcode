#include "solution.h"

int main() {
    Solution *obj = new Solution();
    vector<int> height {2,1,5,6,2,3};
    int ret = obj->largestRectangleArea(height);
    cout << "Max area = " << ret << endl;
    return 0;
}
