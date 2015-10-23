files=Solution.java VersionControl.java
all:
	javac $(files) main.java

run:
	gmake all && java main

test:
	javac -cp .:../core/junit-4.12.jar $(files) tests.java
	java -cp .:../core/junit-4.12.jar:../core/hamcrest-core-1.3.jar org.junit.runner.JUnitCore tests
