#include <iostream>
#include "my_lib.h"

#include "ProjectConfig.h"
#include "loguru.hpp"


int main(int argc, char **argv){

    cout_hello_world();
    print_linalg_vector();

    print_boost_version();

    loguru::init(argc, argv);
    LOG_F(INFO, "Hello from main!");     

    return 0;
}