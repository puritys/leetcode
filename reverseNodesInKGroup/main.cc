// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include "algorithm.h"


int main() {
    int nums[5] = {1,2,3,4,5};
    ListNode *head = createNodes(nums, 5);



    Solution *s = new Solution();
    head = s->reverseKGroup(head, 2);

    printNodes(head);

    return 0;
}
