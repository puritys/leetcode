#include "solution.h"

int main () {
    Solution *obj = new Solution();
    string s = obj->countAndSay(3);
    cout << s << endl;
    return 0;
}
