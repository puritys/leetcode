#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "algorithm.h"
#include <iostream>
#include "smartPerf.h"

void bfsTest(struct TreeNode* node) {/*{{{*/
    bfsAlgorithm(node);
}/*}}}*/

void dfsTest(struct TreeNode* node) {/*{{{*/
    dfsAlgorithm(node);
}/*}}}*/

struct TreeNode* genData(int max) {/*{{{*/
    struct TreeNode *head;
    head = (struct TreeNode*) calloc(1, sizeof(struct TreeNode));
    head->val = 0;
    srand(time(NULL));
    int nums[max];// = {6,4,5,3,1,9,10,2,7,8};
    for (int i = 0; i < max; i++) {
        nums[i] = random() % max;
    }
    addTree(&head, nums, max);

    return head;
}/*}}}*/

int main(int argc, char **argv) {
    int i, runTime, dataRows;
    runTime = 300;
    dataRows = 5000;
    struct TreeNode* node;

    char title[100];
    sprintf(title, "bfs  %d items", dataRows);
    smartPerf::start(title);
    for (i = 0; i < runTime; i++) {
        node = genData(dataRows);
        bfsAlgorithm(node);
        free(node);
    }
    smartPerf::end(true);


    sprintf(title, "dfs  %d items", dataRows);
    smartPerf::start(title);
    for (i = 0; i < runTime; i++) {
        node = genData(dataRows);
        dfsAlgorithm(node);
        free(node);
    }
    smartPerf::end(true);

    smartPerf::print();
    return 0;
}                 


