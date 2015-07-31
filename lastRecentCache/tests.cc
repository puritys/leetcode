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
    LRUCache *c = new LRUCache(3);
    c->set(1, 11);
    ASSERT_EQ(11, c->get(1));
    c->set(2, 21);
    c->set(3, 31);
    c->set(4, 41);
//printMap(c->hash);
    ASSERT_EQ(-1, c->get(1));
    c->set(2, 31);
    c->set(2, 32);
    c->set(2, 33);
    c->set(2, 34);
//printMap(c->hash);
    ASSERT_EQ(34, c->get(2));

}

TEST(empty, success) {
    LRUCache *c = new LRUCache(3);
    ASSERT_EQ(-1, c->get(1));
}

TEST(tt, success) {
    LRUCache *c = new LRUCache(2);
    c->set(2,1);
    c->set(2,2);
    ASSERT_EQ(2, c->get(2));
    c->set(1,1);
    c->set(4,1);
    ASSERT_EQ(-1, c->get(2));
}

TEST(latestUsed, success) {
    LRUCache *c = new LRUCache(2);
    c->set(2,1);
    c->set(1,1);
    ASSERT_EQ(1, c->get(2));
    c->set(4,1);
    ASSERT_EQ(-1, c->get(1));
    ASSERT_EQ(1, c->get(2));

}

TEST(removeFirst, success) {
    LRUCache *c = new LRUCache(2);
    c->set(2,1);
    c->set(1,1);
    c->set(2,3);
    c->set(4,1);

    ASSERT_EQ(-1, c->get(1));
    ASSERT_EQ(3, c->get(2));
}

int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
