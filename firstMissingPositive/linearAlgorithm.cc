#include "algorithm.h"

void print (int *nums, int numsSize) {
    printf("num = ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", *(nums + i));
    }
    printf("\n");
}

int firstMissingPositive(int* nums, int numsSize) {
    if (numsSize == 0 ) return 1;
    int i, j = 0;
    quickSort(nums, 0, numsSize - 1);
    for (i = 0, j = 1; i < numsSize; i++) {
        if (*(nums + i) < j) continue;
        if (*(nums + i) != j) return j;
        j++;
    }
    return j;
}

bool quickSort(int *nums, int orgLeft, int orgRight) {
    int mid, midVal, tmp, l, r;
    if (orgLeft >= orgRight) return false;
    l = orgLeft; r =orgRight;
    midVal = *(nums + orgRight);
    while (1) {
        // find a number large than  midVal.
        while(*(nums + l) < midVal) l++;
        // find a number small than or equal midVal.
        while(*(nums + r) >= midVal) r--;
        if (r <= l) break;
        tmp = *(nums + l);
        *(nums + l) = *(nums + r);
        *(nums + r) = tmp;
    }
    tmp = *(nums + orgRight);
    *(nums +orgRight) = *(nums + l);
    *(nums + l) = tmp;
    quickSort(nums, orgLeft,  l - 1);
    quickSort(nums, l + 1, orgRight);
    return true;
}
