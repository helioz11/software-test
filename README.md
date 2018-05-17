# software_test
[![Build Status](https://travis-ci.org/helioz11/software-test.svg?branch=master)](https://travis-ci.org/helioz11/software-test)
[![codecov](https://codecov.io/gh/helioz11/software-test/branch/master/graph/badge.svg)](https://codecov.io/gh/helioz11/software-test)

Update Jenkinsfile

Support individual testing, follow Makefile
## Makefile
make [all] - make all googletest executable file(unittest & covTest)

make clean - remove all file generate by make

make triangle_*_test - run triangle test (change * to c0/c1/c2/c_MCDC)

make nextdate_*_test - run nextdate test (change * to c0/c1/c2/c_MCDC)

make commission_*_test - run commission test (change * to c0/c1/c2/c_MCDC)

## Steps
### How to execute : 
	cd make
	make
	./(executable file)

### gcov :
	(after run the executable file)
	gcov -b (feature code of the execute file)
	vim (outputfile).c.gcov
