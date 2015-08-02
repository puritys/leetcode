files= algorithm.cc ../core/listNode.cc

all:
	g++ -g -std=c++0x main.cc $(files) && ./a.out

test:
	g++ -g tests.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=full*

perf:
	g++ -g perf.cc $(files) -lsmartPerf  && ./a.out

