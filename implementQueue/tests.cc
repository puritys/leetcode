#include "algorithm.h"
#include "gtest/gtest.h"
using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;                                                                                                                           
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

TEST(normal, success) {
    int size = 10;
    Queue *q = (Queue*) malloc (sizeof(Queue));
    queueCreate(q, size); 
    ASSERT_EQ(true, queueEmpty(q));
    queuePush(q, 1);
    ASSERT_EQ(false, queueEmpty(q));
    queuePush(q, 2);
    queuePush(q, 3);
    ASSERT_EQ(1, queuePeek(q));
    queuePop(q);
    ASSERT_EQ(2, queuePeek(q));
    queuePop(q);
    ASSERT_EQ(3, queuePeek(q));
    queuePop(q);
    ASSERT_EQ(0, queuePeek(q));
    ASSERT_EQ(true, queueEmpty(q));

}

TEST(destroy, success) {
    int size = 10;
    Queue *q = (Queue*) malloc (sizeof(Queue));
    queueCreate(q, size); 
    ASSERT_EQ(true, queueEmpty(q));
    queuePush(q, 1);
    queuePush(q, 2);
    queuePush(q, 3);
    ASSERT_EQ(false, queueEmpty(q));
    queueDestroy(q);
    ASSERT_EQ(true, queueEmpty(q));

    queueCreate(q, 3); 
    queuePop(q);
    ASSERT_EQ(0, queuePeek(q));
    queuePush(q, 90);
    ASSERT_EQ(90, queuePeek(q));
    queuePush(q, -90);
    ASSERT_EQ(90, queuePeek(q));
    queuePush(q, -90);
    ASSERT_EQ(90, queuePeek(q));

}

TEST(queueCircle, success) {
    int size = 5;
    Queue *q = (Queue*) malloc (sizeof(Queue));
    queueCreate(q, size); 
    queuePush(q, 1);
    queuePush(q, 2);
    queuePush(q, 3);
    queuePush(q, 4);
    queuePush(q, 5);

    queuePop(q);
    queuePop(q);
    queuePop(q);
    queuePush(q, 6);
    ASSERT_EQ(4, queuePeek(q));
    queuePop(q);
    ASSERT_EQ(5, queuePeek(q));
    queuePop(q);
    ASSERT_EQ(6, queuePeek(q));

    queuePush(q, 1);
    queuePop(q);
    ASSERT_EQ(1, queuePeek(q));

}

TEST(full, success) {
    int size = 5;
    Queue *q = (Queue*) malloc (sizeof(Queue));
    queueCreate(q, size); 
    queuePush(q, 1);
    queuePush(q, 2);
    queuePush(q, 3);
    queuePush(q, 4);
    queuePush(q, 5);
    queuePush(q, 6);
    ASSERT_EQ(1, queuePeek(q));queuePop(q);
    ASSERT_EQ(2, queuePeek(q));queuePop(q);
    ASSERT_EQ(3, queuePeek(q));queuePop(q);
    ASSERT_EQ(4, queuePeek(q));queuePop(q);
    ASSERT_EQ(5, queuePeek(q));queuePop(q);
    ASSERT_EQ(0, queuePeek(q));queuePop(q);

}

int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
