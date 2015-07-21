// https://leetcode.com/problems/first-missing-positive/
#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"

int main () {
    int *nums = (int *) malloc (sizeof(int) * 10);
    for (int i = 9; i >= 0; i--) {
        *(nums + i) = (i + 1);
    }
    *(nums + 5) = -1;
//    int *nums = (int *) malloc (sizeof(int) * 2);
//    *(nums) = 2;
//    *(nums + 1) = 1;

    int ret = firstMissingPositive(nums, 10);
    printf("val = %d \n", ret);
    return 0;
}
