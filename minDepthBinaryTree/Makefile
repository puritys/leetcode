files= bfsAlgorithm.cc dfsAlgorithm.cc bfsQueueAlgorithm.cc ../core/tree.cc

all:
	g++ -g main.cc $(files) && ./a.out

test:
	g++ -g tests.cc $(files) -lpthread -lgtest && ./a.out

perf:
	g++ -g perf.cc $(files) -lsmartPerf  && ./a.out

