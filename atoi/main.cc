#include <stdio.h>
#include <string.h>
#include <limits.h>
int myAtoi(char* str) {
    int n, i = 0, ret = 0, num;
    bool flag = false;
    char text;
    text = *(str);
    n = strlen(str);
    //trim
    while(text == ' ' && i < n) {
        i++;
        text = *(str + i);
    }

    if (text == '-') {
        flag = true;
        i++;
    } else if (text == '+') {
        i++;
    }
    for (; i < n ; i++) {
        text = *(str+i);
        // 0 - 9 ascii 48 ~ 57 , 0x30 ~ 0x39
        num = (int)text - 0x30;
        if (num >= 0 && num <= 9) {
            if (ret > 214748364 || ret < -214748364) {
                if (flag) return INT_MIN;
                else     return INT_MAX;
            }
            ret = ret*10 + num;
        } else if (ret > 0) {
            break;
        } else {
            return 0;
        }
    }
    if (flag) {
        if (ret < 0) {
            return INT_MIN;
        }
        ret *= -1;
    } else if (ret < 0) {
        return INT_MAX;
    } 

    return ret;
}

int main () {
    printf("num = %d\n", myAtoi("123"));
    printf("num = %d\n", myAtoi("14121421414123"));
    printf("num = %d\n", myAtoi("99999"));
    printf("num = %d\n", myAtoi("-123"));
    printf("num = %d\n", myAtoi("2223"));
    printf("num = %d\n", myAtoi("2a223"));
    printf("num = %d\n", myAtoi("+-2"));
    printf("num = %d\n", myAtoi("    010"));
    printf("num = %d\n", myAtoi("  -0012a42"));//12
    printf("num = %d\n", myAtoi("2147483648"));//"2147483647"
    printf("num = %d\n", myAtoi("      -11919730356x"));//-2147483648











}
