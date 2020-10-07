TESTDIR = Testing/
INCLUDEDIR = Include/;../Include
SOURCEDIR = Source/
OBJECTDIR = ObjectFiles/

CC = g++
CFLAGS = -Wall -Wextra -std=c++14 -g -IInclude 

.PHONY: all clean stack

all: stack
	./stack

stack: $(OBJECTDIR)test.o $(OBJECTDIR)int_test.o $(OBJECTDIR)double_test.o $(TESTDIR)test_lib.h
	$(CC) -o stack $(OBJECTDIR)test.o $(OBJECTDIR)int_test.o $(OBJECTDIR)double_test.o $(CFLAGS)

$(OBJECTDIR)test.o: $(TESTDIR)test.cpp $(TESTDIR)test_lib.h ObjectDir
	$(CC) -c -o $(OBJECTDIR)test.o $(TESTDIR)test.cpp $(CFLAGS)

$(OBJECTDIR)int_test.o: $(TESTDIR)int_test.cpp $(TESTDIR)test_lib.h ObjectDir
	$(CC) -c -o $(OBJECTDIR)int_test.o $(TESTDIR)int_test.cpp $(CFLAGS)

$(OBJECTDIR)double_test.o: $(TESTDIR)double_test.cpp $(TESTDIR)test_lib.h ObjectDir
	$(CC) -c -o $(OBJECTDIR)double_test.o $(TESTDIR)double_test.cpp $(CFLAGS)

ObjectDir:
	mkdir -p ObjectFiles

clean:
	rm -rf *.o ObjectFiles stack
