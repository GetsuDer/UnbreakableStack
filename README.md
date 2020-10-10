# Unbreakable stack

## Description
    Realisation of stack for different types with some safety functions, where types are:
    int, unsigned, double, float, char

## Starting
    To work with this stack, you need to include '"stack_unic.h"' in your code, and, to instanse
    stack template, do '#define TYPE type_you_want_to' (now int and double is working), then
'#include "stack_global.h"', then '#include "stack.cpp"'

### Dependences
    Linux, g++, make

### Run
   'make stack' or 'make all'  will compile and run test program.

#### Output and logging
   Params 'LOG=file_name' and 'ERRLOG=file_name' specify the output files.
   Test results are written into LOG (default log), errors (or commad Stack_Dump)
   cause stack dump into ERRLOG (default errlog)

#### Debug level
  To specify debug level, add param 'DEBUG_LEVEL=level' in make statement, where level in:
      WEAK - check stack correctness before and after each action
      MEDIUM - WEAK + guard birds
      STRONG - MEDIUM + shadow stack copy for data control
  Default value is DEBUG_LEVEL=STRONG, if you want no debug info, write 'DEBUG_LEVEL=NONE'.
  Each debug level adds additional info into errorlon and dumps.

## Documentation
To see the whole documentation, download source code and run 'doxywizard Documentation/Config'
(may be you should also update in dozywizard 'directory in which run doxywizard')
