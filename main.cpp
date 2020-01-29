#include <iostream>
#define CATCH_CONFIG_RUNNER

#include "libs/catch2/catch.hpp"

int runCatchTests()
{
    //This line of code causes the Catch library to
    //run the tests in the project.
    return Catch::Session().run();
}

int main(int argc, char* const argv[]) {

    // For running the tests
    // pass the 'test' parameter when executing
    if(argc > 1){
        std::string test = "test";
        if(!std::strncmp(argv[1],test.c_str(), 4)) {
            return runCatchTests();
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
