files=  solution.cc

all:
	g++ -g -std=c++11 main.cc $(files) && ./a.out

test:
	g++ -g -std=c++11 tests.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=full*

testCpp:
	g++ -g -std=c++11 testsCpp.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=full*


perf:
	g++ -g -std=c++11 perf.cc $(files) -lsmartPerf  && ./a.out
