TESTDIR = Testing/
SOURCEDIR = Source/
OBJECTDIR = ObjectFiles/
NEED = Source/stack.cpp ObjectDir Source/stack.cpp Include/stack.h
CC = g++
CFLAGS = -Wall -Wextra -Wformat -std=c++14 -g -IInclude -ISource 
LOG = log
ERRLOG = errlog
D_ADD = 
DEBUG_LEVEL = FULL

ifeq ($(DEBUG_LEVEL), NONE)
 D_ADD = -DNDEBUG
endif

ifeq ($(DEBUG_LEVEL), WEAK)
 D_ADD = -DDEBUG_CHECK_CORRECTNESS
endif

ifeq ($(DEBUG_LEVEL), MEDIUM)
 D_ADD = -DDEBUG_CHECK_CORRECTNESS -DDEBUC_BIRDS
endif

ifeq ($(DEBUG_LEVEL), STRONG)
 D_ADD = -DDEBUG_CHECK_CORRECTNESS -DDEBUG_BIRDS -DDEBUG_HASH
endif

ifeq ($(DEBUG_LEVEL), FULL)
 D_ADD = -DDEBUG_CHECK_CORRECTNESS -DDEBUG_BIRDS -DDEBUG_HASH -DSHADOW_CONTROL
endif

.PHONY: all clean stack
all: stack
	./stack > $(LOG) 2> $(ERRLOG)

stack: $(OBJECTDIR)test.o $(OBJECTDIR)int_test.o $(OBJECTDIR)double_test.o $(OBJECTDIR)diff_stacks.o $(TESTDIR)test_lib.h
	$(CC) -o stack $(OBJECTDIR)test.o $(OBJECTDIR)int_test.o $(OBJECTDIR)double_test.o $(OBJECTDIR)diff_stacks.o $(CFLAGS) $(D_ADD)

$(OBJECTDIR)test.o: $(TESTDIR)test.cpp $(TESTDIR)test_lib.h $(TESTDIR)test_lib_unic.h $(NEED)
	$(CC) -c -o $(OBJECTDIR)test.o $(TESTDIR)test.cpp $(CFLAGS) $(D_ADD)

$(OBJECTDIR)int_test.o: $(TESTDIR)int_test.cpp $(TESTDIR)test_lib.h $(NEED)
	$(CC) -c -o $(OBJECTDIR)int_test.o $(TESTDIR)int_test.cpp $(CFLAGS) $(D_ADD)

$(OBJECTDIR)double_test.o: $(TESTDIR)double_test.cpp $(TESTDIR)test_lib.h $(NEED)
	$(CC) -c -o $(OBJECTDIR)double_test.o $(TESTDIR)double_test.cpp $(CFLAGS) $(D_ADD)

$(OBJECTDIR)diff_stacks.o: $(TESTDIR)diff_stacks.cpp $(TESTDIR)test_lib.h $(NEED)
	$(CC) -c -o $(OBJECTDIR)diff_stacks.o $(TESTDIR)diff_stacks.cpp $(CFLAGS) $(D_ADD)

ObjectDir:
	mkdir -p ObjectFiles

clean:
	rm -rf *.o ObjectFiles stack $(LOG) $(ERRLOG)
