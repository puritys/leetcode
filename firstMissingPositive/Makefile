files= linearAlgorithm.cc ../core/tree.cc                                                                      

all:
	g++ -g main.cc $(files) && ./a.out

test:
	g++ -g tests.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=sameNumber*

perf:
	g++ -g perf.cc $(files) -lsmartPerf  && ./a.out
