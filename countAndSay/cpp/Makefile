files = solution.cc
main:
	g++ -g -std=c++0x main.cc $(files) && ./a.out

test:
	g++ -g -std=c++0x tests.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=*simple2*

perf:
	g++ -g -std=c++0x perf.cc $(files) -lsmartPerf  && ./a.out
