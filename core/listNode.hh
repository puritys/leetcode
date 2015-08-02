#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};

ListNode* createNodes(int val[], int size);
void addNode(ListNode *head, int val);
void printNodes(ListNode *head);


