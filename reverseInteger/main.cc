#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits.h>
#include <math.h>
class Solution {
    public:
        static int reverse(int x);
};
int Solution::reverse(int n) {
    int ret = 0;
    bool flag = true;
    if (n >> 31 & 1) {flag = false; n = ~n + 1;}
    if (n >> 31 & 1) return 0; //-2147483648
    //printf("n = %d", n);
    while (n != 0) {
        //printf(" v = %d \n", ret);
        if (ret > 214748364) return 0;
       // if (ret > 214748364 || ret < -214748364) return 0;
        ret = ret * 10;
        ret += n % 10;
        n = n / 10;
    }
    if (!flag) ret *= -1;
    return ret;
}

//assumes little endian
void printBits(int n) {
    int s = 0;
    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");
        s++;
        n >>= 1;
        if (s >= 32) break;
    }
    printf("num = %d\n", s);
}

int main (int argc, char** argv) {
///    int a = (0b01111111 << 24) | (0xff << 16) | (0xff << 8) | (0xff);
    std::cout << INT_MAX << std::endl;

    std::cout << Solution::reverse(123) << std::endl;
    std::cout << Solution::reverse(-123) << std::endl;
    std::cout << Solution::reverse(1463847412) << std::endl;
    std::cout << Solution::reverse(-2147483412) << std::endl;

    std::cout <<"zero\n" ;
    std::cout << Solution::reverse(-1563847412) << std::endl;
    std::cout << Solution::reverse(-2147483648) << std::endl;
    std::cout << Solution::reverse(1534236469) << std::endl;
    std::cout << Solution::reverse(1563847412) << std::endl;







    return 1;
//    char* source = argv[1];
//    char text;
//    int n = strlen(source);
//    text = *source;
//    //printf("input = %s \n", source);
//    if (text == '-') {
//        printf("%c", text);
//    }
//
//    int i = n - 1;
//    while(i >= 0) {
//        text = *(source + i);
//        if (text != '-') {
//            printf("%c", text);
//        }
//        i--;
//    }
//    return 1;
}

// version 1
/*
int Solution::reverse(int x) {
    int ret = 0;
    int n = x;
    int length = 0;
    while (n != 0) {
        ret = ret * 10;
        ret += n % 10;
        n = n / 10;
        length++;
    }

    if (length >= 10) {
        int mod = pow(10, --length);
        int max = INT_MAX / mod;
        while (mod) {
            n = abs(x % 10);
           // printf("max = %d n = %d\n", max, n);
            if (n > max) {
                return 0;
            } else if (n < max) {
                break;
            }
            x /= 10;
            mod = pow(10, --length);
            max = (INT_MAX / mod) % 10;
        }
   }


    return ret;
}
*/

