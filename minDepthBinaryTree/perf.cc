#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "algorithm.h"
#include <iostream>
#include "smartPerf.h"

struct TreeNode* genData(int max) {/*{{{*/
    struct TreeNode *head;
    head = (struct TreeNode*) calloc(1, sizeof(struct TreeNode));
    head->val = 0;
    srand(time(NULL));
    int nums[max];
    for (int i = 0; i < max; i++) {
        nums[i] = random() % max;
    }
    addTree(&head, nums, max);

    return head;
}/*}}}*/

struct TreeNode* genNormalData() {/*{{{*/
    struct TreeNode *head;
    head = (struct TreeNode*) calloc(1, sizeof(struct TreeNode));
    head->val = 0;
    srand(time(NULL));
    int nums[20] = {17, 4, 5, 3, 1, 6, 2,7,8,11,18,19,20, 14,15, 9, 16, 12,13, 10};
    addTree(&head, nums, 20);
    return head;
}/*}}}*/


int main(int argc, char **argv) {
    int i, runTime, dataRows;
    runTime = 100;
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

    sprintf(title, "bfs with queue  %d items", dataRows);
    smartPerf::start(title);
    for (i = 0; i < runTime; i++) {
        node = genData(dataRows);
        bfsQueueAlgorithm(node);
        free(node);
    }
    smartPerf::end(true);

    runTime = 10000;
    sprintf(title, "bfs  20 items on normal array");
    smartPerf::start(title);
    for (i = 0; i < runTime; i++) {
        node = genNormalData();
        bfsAlgorithm(node);
        free(node);
    }
    smartPerf::end(true);


    sprintf(title, "dfs  20 items on normal array");
    smartPerf::start(title);
    for (i = 0; i < runTime; i++) {
        node = genNormalData();
        dfsAlgorithm(node);
        free(node);
    }
    smartPerf::end(true);

    sprintf(title, "dfs with queue  20 items on normal array");
    smartPerf::start(title);
    for (i = 0; i < runTime; i++) {
        node = genNormalData();
        bfsQueueAlgorithm(node);
        free(node);
    }
    smartPerf::end(true);

    smartPerf::print();
    return 0;
}                 


