#include "solution.h"



string Solution::countAndSay(int n) {
    if (0 == n) return "";  
    if (1 == n) return "1";
    string ret = "1";
    string next = "";
    for (int i = 2; i <= n; i++) {
        int count = 0;
        char countChar;
        for (auto ch = ret.begin(); ch != ret.end(); ch++) {
            if (countChar == *ch) {
                count++;
            } else {
                if (count > 0) next += to_string(count) + countChar;
                countChar = *ch;
                count = 1;
            }
        }
        if (count > 0) next += to_string(count) + countChar;
        ret = next; next = "";
    }
    return ret;
}
