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

TEST(zeroZero, success) {
    int size = 2;
    int x[10] = {0, 0};
    int y[10] = {0, 0};
    struct Point *point = createData(x, y, size);
    int max = maxPoints(point, size);
    ASSERT_EQ(2, max);
}


TEST(samePoint, success) {
    int size = 3;
    int x[10] = {0, 1, 0};
    int y[10] = {0, 1, 0};
    struct Point *point = createData(x, y, size);
    int max = maxPoints(point, size);
    ASSERT_EQ(3, max);
}

TEST(normal, success) {
    int size = 9;
    int x[10] = {0, 1,2,3,2,2, 3,4,5};//,6,7,8,9,10};
    int y[10] = {0, 1,2,3,1,0, 1,1,1};//,6,7,8,9,10};
    struct Point *point = createData(x, y, size);
    int max = maxPoints(point, size);
    ASSERT_EQ(5, max);

}
//[[84,250],[0,0],[1,0],[0,-70],[0,-70],[1,-1],[21,10],[42,90],[-42,-230]]
TEST(complicate, success) {
    int size = 9;
    int x[10] = {84, 0, 1, 0 , 0,  1, 21, 42, -42};
    int y[10] = {250, 0,0, -70, -70, -1, 10, 90 ,-230};
    struct Point *point = createData(x, y, size);
    int max = maxPoints(point, size);
    ASSERT_EQ(6, max);
}

int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
