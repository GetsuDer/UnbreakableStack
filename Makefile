TESTDIR = Testing/
INCLUDEDIR = Include/
SOURCEDIR = Source/
OBJECTDIR = ObjectFiles/

CC = g++
CFLAGS = -Wall -Wextra -Wfloat-equal -std=c++14 -g -IInclude 

.PHONY: all clean stack

all: stack
	./stack

stack: $(SOURCEDIR)main.cpp $(SOURCEDIR)stack.cpp
	$(CC) -o stack $(SOURCEDIR)main.cpp $(CFLAGS)

ObjectDir:
	mkdir -p ObjectFiles

clean:
	rm -rf *.o ObjectFiles stack
