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
    QueueCpp *q = new QueueCpp();
    q->push(1);
    q->push(2);
    ASSERT_EQ(1, q->peek());
    ASSERT_EQ(false, q->empty());

    q->pop();
    ASSERT_EQ(2, q->peek());
    q->pop();
    ASSERT_EQ(true, q->empty());

}

int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
