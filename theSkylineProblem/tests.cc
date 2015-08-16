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

TEST(Normal, success) {
    string data ("2 9 10, 3 7 15, 5 12 12, 15 20 10, 19 24 8");
    vector<vector<int> > v = createVector(data); 

    Solution *o = new Solution();
    vector<pair<int, int>> points = o->getSkyline(v);
    vector<pair<int, int>>::iterator pit;
    pit = points.begin();
    ASSERT_EQ(2, pit->first);
    ASSERT_EQ(10, pit->second);

    ++pit;
    ASSERT_EQ(3, pit->first);
    ASSERT_EQ(15, pit->second);

    ++pit;
    ASSERT_EQ(7, pit->first);
    ASSERT_EQ(12, pit->second);

    ++pit;
    ASSERT_EQ(12, pit->first);
    ASSERT_EQ(0, pit->second);

    ++pit;
    ASSERT_EQ(15, pit->first);
    ASSERT_EQ(10, pit->second);

    ++pit;
    ASSERT_EQ(20, pit->first);
    ASSERT_EQ(8, pit->second);

    ++pit;
    ASSERT_EQ(24, pit->first);
    ASSERT_EQ(0, pit->second);

}

TEST(N2, success) {/*{{{*/
    string data ("0 2 3,2 5 3");
    vector<vector<int> > v = createVector(data); 

    Solution *o = new Solution();
    vector<pair<int, int>> points = o->getSkyline(v);
    vector<pair<int, int>>::iterator pit;

//printPairVector(points);

    pit = points.begin();
    ASSERT_EQ(0, pit->first);
    ASSERT_EQ(3, pit->second);

    ++pit;
    ASSERT_EQ(5, pit->first);
    ASSERT_EQ(0, pit->second);
}/*}}}*/

TEST(N3, success) {/*{{{*/
    string data ("1 2 1,1 2 2,1 2 3");
    vector<vector<int> > v = createVector(data); 

    Solution *o = new Solution();
    vector<pair<int, int>> points = o->getSkyline(v);
    vector<pair<int, int>>::iterator pit;

//printPairVector(points);

    pit = points.begin();
    ASSERT_EQ(1, pit->first);
    ASSERT_EQ(3, pit->second);

    ++pit;
    ASSERT_EQ(2, pit->first);
    ASSERT_EQ(0, pit->second);
}/*}}}*/



TEST(big, success) {/*{{{*/
    string data ("1 10001 10000,2 10001 9999,3 10001 9998,4 10001 9997,5 100019 996,6 10001 9995,7 10001 9994,8 10001 9993,9 10001 9992,10 10001 9991,11 10001 9990,12 10001 9989,13 10001 9988,14 10001 9987");

    vector<vector<int> > v = createVector(data); 

    Solution *o = new Solution();
    vector<pair<int, int>> points = o->getSkyline(v);

//printPairVector(points);

    vector<pair<int, int>>::iterator pit;
    pit = points.begin();
    ASSERT_EQ(1, pit->first);
    ASSERT_EQ(10000, pit->second);

    ++pit;
    ASSERT_EQ(10001, pit->first);
    ASSERT_EQ(996, pit->second);

    ++pit;
    ASSERT_EQ(100019, pit->first);
    ASSERT_EQ(0, pit->second);

}/*}}}*/

TEST(N4, success) {/*{{{*/
    string data ("3 7 8,3 8 7,3 9 6");//,3 10 5,3 11 4,3 12 3,3 13 2,3 14 1");
    vector<vector<int> > v = createVector(data); 

    Solution *o = new Solution();
    vector<pair<int, int>> points = o->getSkyline(v);

//printPairVector(points);

    vector<pair<int, int>>::iterator pit;
    pit = points.begin();
    ASSERT_EQ(3, pit->first);
    ASSERT_EQ(8, pit->second);

    ++pit;
    ASSERT_EQ(7, pit->first);
    ASSERT_EQ(7, pit->second);

    ++pit;
    ASSERT_EQ(8, pit->first);
    ASSERT_EQ(6, pit->second);

}/*}}}*/
//[[2,4,70],[3,8,30],[6,100,41],[7,15,70],[10,30,102],[15,25,76],[60,80,91],[70,90,72],[85,120,59]]
//      [[2,70],[4,30],[6,41],[7,70],[10,102],[30,41],[60,91],[80,72],[90,59],[120,0]]
// fail [[2,70],[4,30],[6,41],[7,70],[10,102],        [60,91],[80,72],[90,59],[120,0]]
TEST(N5, success) {/*{{{*/
    string data ("2 4 70,3 8 30,6 100 41,7 15 70,10 30 102,15 25 76,60 80 91,70 90 72,85 120 59");
    vector<vector<int> > v = createVector(data); 

    Solution *o = new Solution();
    vector<pair<int, int>> points = o->getSkyline(v);

printPairVector(points);

    vector<pair<int, int>>::iterator pit;
    pit = points.begin();
    ASSERT_EQ(2, pit->first);
    ASSERT_EQ(70, pit->second);

    ++pit;
    ASSERT_EQ(4, pit->first);
    ASSERT_EQ(30, pit->second);

    ++pit;
    ASSERT_EQ(6, pit->first);
    ASSERT_EQ(41, pit->second);

    ++pit;
    ASSERT_EQ(7, pit->first);
    ASSERT_EQ(70, pit->second);

    ++pit;
    ASSERT_EQ(10, pit->first);
    ASSERT_EQ(102, pit->second);
    ++pit;
    ASSERT_EQ(30, pit->first);
    ASSERT_EQ(41, pit->second);

    ++pit;
    ASSERT_EQ(60, pit->first);
    ASSERT_EQ(91, pit->second);

}/*}}}*/

TEST(N6, success) {
    string data ("1 5 1,2 4 2,3 5 3,5 10 5");
    vector<vector<int> > v = createVector(data); 

    Solution *o = new Solution();
    vector<pair<int, int>> points = o->getSkyline(v);
    vector<pair<int, int>>::iterator pit;

//printPairVector(points);

    pit = points.begin();
    ASSERT_EQ(1, pit->first);
    ASSERT_EQ(1, pit->second);

    ++pit;
    ASSERT_EQ(2, pit->first);
    ASSERT_EQ(2, pit->second);
    ++pit;
    ASSERT_EQ(3, pit->first);
    ASSERT_EQ(3, pit->second);
    ++pit;
    ASSERT_EQ(5, pit->first);
    ASSERT_EQ(5, pit->second);
    ++pit;
    ASSERT_EQ(10, pit->first);
    ASSERT_EQ(0, pit->second);


}

TEST(N7, success) {
    string data ("1000 10001 11001,9000 10001 19001");
    vector<vector<int> > v = createVector(data); 

    Solution *o = new Solution();
    vector<pair<int, int>> points = o->getSkyline(v);
    vector<pair<int, int>>::iterator pit;

printPairVector(points);

    pit = points.begin();
    ASSERT_EQ(1000, pit->first);
    ASSERT_EQ(11001, pit->second);

    ++pit;
    ASSERT_EQ(9000, pit->first);
    ASSERT_EQ(19001, pit->second);
    ++pit;
    ASSERT_EQ(10001, pit->first);
    ASSERT_EQ(0, pit->second);

}


TEST(Complicate, success) {/*{{{*/
    string data ("6765 184288 53874,13769 607194 451649,43325 568099 982005,47356 933141 123943,59810 561434 119381,75382 594625 738524,111895 617442 587304,143767 869128 471633,195676 285251 107127,218793 772827 229219,316837 802148 899966,329669 790525 416754,364886 882642 535852,368825 651379 6209,382318 992082 300642,397203 478094 436894,436174 442141 612149,502967 704582 918199,503084 561197 625737,533311 958802 705998,565945 674881 149834,615397 704261 746064,624917 909316 831007,788731 924868 633726,791965 912123 438310");

    vector<vector<int> > v = createVector(data); 

    Solution *o = new Solution();
    vector<pair<int, int>> points = o->getSkyline(v);
    vector<pair<int, int>>::iterator pit;

//printPairVector(points);

    pit = points.begin();
    ASSERT_EQ(6765, pit->first);
    ASSERT_EQ(53874, pit->second);

    ++pit;
    ASSERT_EQ(13769, pit->first);
    ASSERT_EQ(451649, pit->second);
    ++pit;
    ASSERT_EQ(43325, pit->first);
    ASSERT_EQ(982005, pit->second);
    ++pit;
    ASSERT_EQ(568099, pit->first);
    ASSERT_EQ(918199, pit->second);
    ++pit;
    ASSERT_EQ(704582, pit->first);
    ASSERT_EQ(899966, pit->second);
    ++pit;
    ASSERT_EQ(802148, pit->first);
    ASSERT_EQ(831007, pit->second);
    ++pit;
    ASSERT_EQ(909316, pit->first);
    ASSERT_EQ(705998, pit->second);
    ++pit;
    ASSERT_EQ(958802, pit->first);
    ASSERT_EQ(300642, pit->second);
    ++pit;
    ASSERT_EQ(992082, pit->first);
    ASSERT_EQ(0, pit->second);


}/*}}}*/


int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
