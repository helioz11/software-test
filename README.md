# software_test
[![Build Status](https://travis-ci.org/helioz11/software-test.svg?branch=master)](https://travis-ci.org/helioz11/software-test)
[![codecov](https://codecov.io/gh/helioz11/software-test/branch/master/graph/badge.svg)](https://codecov.io/gh/helioz11/software-test)

Update Jenkinsfile

Makefile
make [all] - make all googletest executable file(unittest & covTest)
make clean - remove all file generate by make

How to run
steps : 
	cd make
	make
	./(executable file)

gcov :
	(after run the executable file)
	gcov -b (feature code of the execute file)
	vim (outputfile).c.gcov
