files=  algorithm.cc algorithmQueue.cc

all:
	g++ -g main.cc $(files) && ./a.out

test:
	g++ -g tests.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=full*

perf:
	g++ -g perf.cc $(files) -lsmartPerf  && ./a.out
