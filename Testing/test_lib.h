#ifndef H_TEST_LIB
#define H_TEST_LIB

//! This variable counts number of tests which were run by macro TEST
extern int number_of_tests;

//! This variable counts number of successfully passed tests
extern int passed;

//! This variable counts number of unsuccessfully passed tests
extern int failed;

//! This varaible shows the current test state
extern bool test_state;

//! This should be written at the beginning of the each test
#define TEST_BEGIN \
    test_state = true;\
    number_of_tests++;\
    std::cerr << "Test # " << number_of_tests << std::endl;

//! This macro compares the arguments and updates the test state
#define TEST(code, result) \
    std::cerr << "checking " << #code << " == " << #result << std::endl;\
    if ((code) != (result)) {\
        test_state = false;\
        std::cerr << COLOR_RED << __FILE__ << ' ' << __LINE__ << COLOR_WHITE << std::endl;\
    } else {\
        std::cerr << COLOR_GREEN << "OK" << COLOR_WHITE << std::endl;\
    }

//! This macro means the end of the current test
#define TEST_END \
    if (test_state) {\
        std::cerr << COLOR_GREEN << "[PASSED]" << COLOR_WHITE;\
    } else {\
        failed++;\
        std::cerr << COLOR_RED << "[FAILED]" << COLOR_WHITE;\
    }\
    std::cerr << "Test # " <<  number_of_tests  << std::endl << std::endl;


//! This macro can be started to see the results of previous tests
#define TEST_SUMMARY \
{\
    std::cerr << "total tests: " << number_of_tests << std::endl;\
    std::cerr << "passed: " << passed << std::endl;\
    std::cerr << "failed: " << failed << std::endl;\
    if (failed) {\
        std::cerr << COLOR_RED << "testing unsuccessfull" << COLOR_WHITE << std::endl;\
    } else {\
        std::cerr << COLOR_GREEN << "testing successfull" << COLOR_WHITE << std::endl;\
    }\
}

//! Change the console text color to green
#define COLOR_GREEN "\x1b[32m"

//! Change the console text color to red
#define COLOR_RED "\x1b[31m"

//! Change the console text color to white
#define COLOR_WHITE "\x1b[0m"

#define EPS 1e-6

void test_int();
void test_double();
#endif
