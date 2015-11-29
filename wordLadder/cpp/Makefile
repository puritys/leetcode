files=  solution.cc solutionShortestPath.cc solutionBFS_v1.cc

all:
	g++ -g -std=c++0x main.cc $(files) && ./a.out

test:
	g++ -g -std=c++0x tests.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=full*

testCpp:
	g++ -g testsCpp.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=full*


perf:
	g++ -g -std=c++0x perf.cc $(files) -lsmartPerf  && ./a.out
