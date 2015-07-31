files=  algorithm.cc algorithmV1.cc algorithmLinear.cc util.cc

all:
	g++ -g main.cc $(files) && ./a.out

test:
	g++ -g tests.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=normal*

testCpp:
	g++ -g testsCpp.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=full*


perf:
	g++ -g perf.cc $(files) -lsmartPerf  && ./a.out
