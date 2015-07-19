#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "algorithm.h"
#include <iostream>
#include "smartPerf.h"

void test1(struct ListNode* node) {/*{{{*/
    node = sortList(node);
}/*}}}*/

void test2(struct ListNode* node) {/*{{{*/
    sortListPartitionV1(node);
}/*}}}*/

struct ListNode* genData(int max) {/*{{{*/
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    srand(time(NULL));
    node->val = 1;
    node->next = NULL;
    for (int i = 1; i < max; i++) {
        insert(node, random() % 5000 +1);
    }
    return node;
}/*}}}*/

struct ListNode* genSimilarData(int max) {/*{{{*/
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = 1;
    node->next = NULL;
    for (int i = 1; i < max; i++) {
        insert(node, random() % 3 +1);
    }
    return node;
}/*}}}*/


int main(int argc, char **argv) {
    int i, runTime, dataRows;
    runTime = 30000;
    dataRows = 10;
    struct ListNode* node;

    char title[100];
    sprintf(title, "Sort by merge %d items", dataRows);
    smartPerf::start(title);
    for (i = 0; i < runTime; i++) {
        node = genData(dataRows);
        test1(node);
        free(node);
    }
    smartPerf::end(true);


    sprintf(title, "Sort by partition %d items", dataRows);
    smartPerf::start(title);
    for (i = 0; i < runTime; i++) {
        node = genData(dataRows);
        test2(node);
        free(node);
    }
    smartPerf::end(true);


    dataRows = 3;
    sprintf(title, "Sort by merge %d items, similar number", dataRows);
    smartPerf::start(title);
    for (i = 0; i < runTime; i++) {
        node = genSimilarData(dataRows);
        test1(node);
        free(node);
    }
    smartPerf::end(true);

    sprintf(title, "Sort by partition %d items, similar number", dataRows);
    smartPerf::start(title);
    for (i = 0; i < runTime; i++) {
        node = genSimilarData(dataRows);
        test2(node);
        free(node);
    }
    smartPerf::end(true);





    smartPerf::print();
    return 0;
}                 


