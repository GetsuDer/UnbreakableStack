# Unbreakable stack

## Description
    Realisation of stack for different types with (in future) some safety functions
## Starting
    To work with this stack, you need to include '"stack_unic.h"' in your code, and, to instanse
    stack template, do '#define TYPE type_you_want_to' (now int and double is working), then
'#include "stack_global.h"', then '#include "stack.cpp"'
### Dependences
    Linux, g++, make
### Run
    'make stack' or 'make all'  will compile and run test program.
   Params 'LOG=file_name' and 'ERRLOG=file_name' specify the output files.
 Test results are written into LOG (default log), errors (or commad Stack_Dump)
    cause stack dump into ERRLOG (default errlog)  
## After run
    In file
## Documentation
To see the whole documentation, download source code and run 'doxywizard Documentation/Config'
(may be you should also update in dozywizard 'directory in which run doxywizard')
