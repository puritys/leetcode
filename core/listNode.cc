#include "listNode.hh"

void addNode(ListNode *head, int val) {
    ListNode *newNode = new ListNode(val);
    ListNode *tmp;
    if (head == NULL) {
        head = newNode; 
    } else {
        tmp = head;
        while(tmp && tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

ListNode* createNodes(int val[], int size) {
    ListNode *head = new ListNode(val[0]);
    int i;
    ListNode *tmp;
    tmp = head;
    while(tmp && tmp->next) {
        tmp = tmp->next;
    }

    for (i = 1 ; i < size ; i++) {
        ListNode *newNode = new ListNode(val[i]);
        tmp->next = newNode;
        tmp = tmp->next;
    }
    return head;
}

void printNodes(ListNode *head) {
    std::cout << std::endl;
    ListNode *tmp = head;
    while(tmp) {
        std::cout << tmp->val << std::endl;
        tmp = tmp->next;
    }
}
