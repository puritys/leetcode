#include "algorithm.h"
#include <cctype>
#include <algorithm>

string Solution::trim(string& str)/*{{{*/
{
    int length = str.length();
    for (int i = 0; i < length; i++) {
        if (str.at(i) == ' ') {
            str.erase(i, 1); i = -1;
            length--;
        } else {
            break;
        }
    }
    for (int i = length - 1; i > 0 ; i--) {
        if (str.at(i) == ' ') {
            str.erase(i, 1);
            length--; i = length;
        } else {
            break;
        }
    }
    return str;
}/*}}}*/

string Solution::getNumber(string s, int *start, bool *isNumber) {/*{{{*/
    bool isSecondNum = false;
    if (*start > 0) isSecondNum = true;
    *isNumber = true;
    bool gotNumber = false;
    int dotCount = 0, signCount = 0;
    string str = "";
    int length = s.length();
    for (; (*start) < length; (*start)++) {
        int c = (int) (s.at(*start));
        if ((c >= 48 && c <= 57) 
            || c == (int)'.'
           ) {
            str += c;
            gotNumber = true;
            if (c == (int)'.') {
                if (true == isSecondNum) {
                    *isNumber = false;
                    return "";
                }
                dotCount++;
                if (dotCount >= 2) {
                    *isNumber = false;
                    return "";
                }
            }
        } else if (gotNumber == false 
                   && (c == (int)'-' || c == (int)'+')) {
            if (++signCount == 2) {
                *isNumber = true;
                return "";
            }
        } else {
            return str;
        } 
    }
    return str;
}/*}}}*/

bool Solution::isNumber(string s) {/*{{{*/
    int *index = new int(0);
    bool isNumber = 0;
    string num1 = "", num2 = "";
    char expo;
    if (!s.empty()) s = trim(s);
    if (s.empty()) return false;
    int length = s.length();

    num1 = getNumber(s, index, &isNumber);
    if (false == isNumber) return false;
    if (*index < length) {
        expo = s.at(*index);
        if (expo == 'e') {
            (*index)++;
        } else if ((int) expo < 48 || (int) expo > 57) {
            return false;
        }
    }
    num2 = getNumber(s, index, &isNumber);
    if (false == isNumber || (*index) != length) return false;

    if (!num1.empty() && num1 != ".") {
        if (expo == 'e') {
            if (!num2.empty() && num2 != ".") return true;
            return false;
        }
        return true;
    }
    return false;
}/*}}}*/

void Solution::print(string n, char expo, string n2) {
    cout << "num1 = '" << n << "'" << endl;
    cout << "expo = '" << expo << "'" << endl;
    cout << "num2 = '" << n2 << "'" << endl;
}


