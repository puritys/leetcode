#include "algorithm.h"

void QueueCpp::push(int x) {
    input.push(x);
}

void QueueCpp::pop(void) {
    peek();
    output.pop();
}

int QueueCpp::peek(void) {
    if (output.empty()) {
        while (input.size()) output.push(input.top()), input.pop();
    }
    return output.top();
}

bool QueueCpp::empty(void) {
    return input.empty() && output.empty();
}
