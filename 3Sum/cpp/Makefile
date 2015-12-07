files = solution.cc solutionVersion1.cc solutionOthers.cc
main:
	g++ -g -std=c++0x main.cc $(files) && ./a.out

test:
	g++ -g -std=c++0x tests.cc $(files) -lpthread -lgtest && ./a.out #--gtest_filter=*large*

perf:
	g++ -g -std=c++0x perf.cc $(files) -lsmartPerf  && ./a.out
