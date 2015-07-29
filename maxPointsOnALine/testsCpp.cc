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

vector<struct Point> createTestData(int x[], int y[], int size) {
    vector<struct Point> points;
    vector<struct Point>::iterator it;
    for (int i = 0; i < size; i++) {
        struct Point point = {x[i], y[i]};
        points.push_back(point);
    }
    return points;
}

TEST(zeroZero, success) {
    int size = 0;
    Solution *obj = new Solution();
    vector<struct Point> points;
    int max = obj->maxPoints(points);
    ASSERT_EQ(0, max);
}


TEST(samePoint, success) {
    int size = 3;
    int x[10] = {0, 1, 0};
    int y[10] = {0, 1, 0};
    Solution *obj = new Solution();
    vector<struct Point> points = createTestData(x, y ,size);
    int max = obj->maxPoints(points);
    ASSERT_EQ(3, max);
}

TEST(samePoint2, success) {
    int size = 3;
    int x[10] = {1, 1, 1};
    int y[10] = {1, 1, 1};
    Solution *obj = new Solution();
    vector<struct Point> points = createTestData(x, y ,size);
    int max = obj->maxPoints(points);
    ASSERT_EQ(3, max);
}

TEST(normal, success) {
    int size = 9;
    int x[10] = {0, 1,2,3,2,2, 3,4,5};//,6,7,8,9,10};
    int y[10] = {0, 1,2,3,1,0, 1,1,1};//,6,7,8,9,10};
    Solution *obj = new Solution();
    vector<struct Point> points = createTestData(x, y ,size);
    int max = obj->maxPoints(points);

    ASSERT_EQ(5, max);

}
//[[84,250],[0,0],[1,0],[0,-70],[0,-70],[1,-1],[21,10],[42,90],[-42,-230]]
TEST(complicate, success) {
    int size = 9;
    int x[10] = {84, 0, 1, 0 , 0,  1, 21, 42, -42};
    int y[10] = {250, 0,0, -70, -70, -1, 10, 90 ,-230};
    Solution *obj = new Solution();
    vector<struct Point> points = createTestData(x, y ,size);
    int max = obj->maxPoints(points);
    ASSERT_EQ(6, max);
}

int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
