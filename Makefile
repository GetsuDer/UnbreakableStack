TESTDIR = Testing/
INCLUDEDIR = Include/;../Include
SOURCEDIR = Source/
OBJECTDIR = ObjectFiles/
NEED = Source/stack.cpp ObjectDir Source/stack_unic.cpp
CC = g++
CFLAGS = -Wall -Wextra -std=c++14 -g -IInclude -ISource 
LOG = log
ERRLOG = errlog
.PHONY: all clean stack

all: stack
	./stack > $(LOG) 2> $(ERRLOG)

stack: $(OBJECTDIR)test.o $(OBJECTDIR)int_test.o $(OBJECTDIR)double_test.o $(OBJECTDIR)diff_stacks.o $(TESTDIR)test_lib.h
	$(CC) -o stack $(OBJECTDIR)test.o $(OBJECTDIR)int_test.o $(OBJECTDIR)double_test.o $(OBJECTDIR)diff_stacks.o $(CFLAGS)

$(OBJECTDIR)test.o: $(TESTDIR)test.cpp $(TESTDIR)test_lib.h $(TESTDIR)test_lib_unic.h $(NEED)
	$(CC) -c -o $(OBJECTDIR)test.o $(TESTDIR)test.cpp $(CFLAGS)

$(OBJECTDIR)int_test.o: $(TESTDIR)int_test.cpp $(TESTDIR)test_lib.h $(NEED)
	$(CC) -c -o $(OBJECTDIR)int_test.o $(TESTDIR)int_test.cpp $(CFLAGS)

$(OBJECTDIR)double_test.o: $(TESTDIR)double_test.cpp $(TESTDIR)test_lib.h $(NEED)
	$(CC) -c -o $(OBJECTDIR)double_test.o $(TESTDIR)double_test.cpp $(CFLAGS)

$(OBJECTDIR)diff_stacks.o: $(TESTDIR)diff_stacks.cpp $(TESTDIR)test_lib.h $(NEED)
	$(CC) -c -o $(OBJECTDIR)diff_stacks.o $(TESTDIR)diff_stacks.cpp $(CFLAGS)
ObjectDir:
	mkdir -p ObjectFiles

clean:
	rm -rf *.o ObjectFiles stack $(LOG) $(ERRLOG)
