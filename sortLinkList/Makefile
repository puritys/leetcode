files=partitionAlgorithm.cc mergeAlgorithm.cc linkList.cc

all:
	g++ -g main.cc partitionAlgorithm.cc mergeAlgorithm.cc  linkList.cc && ./a.out

test:
	g++ -g tests.cc partitionAlgorithm.cc mergeAlgorithm.cc linkList.cc  -lpthread -lgtest && ./a.out

perf:
	g++ -g perf.cc $(files) -lsmartPerf  && ./a.out

