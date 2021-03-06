
#include "my_lib.h"

bool print_hello_world(){

    printf("Hello World \n");
    return true;
}

bool cout_hello_world(){
    std::cout << "Servus" << std::endl;
    return true;

}

linalg::aliases::float3 print_linalg_vector(){
    linalg::aliases::float3 my_float3{1,2,3};
    std::cout << "Vec: " << my_float3[0] << ", " << my_float3[1] << ", " << my_float3[2] << std::endl;
    return my_float3;
}

bool print_boost_version(){
    std::cout << "Boost version: " << BOOST_VERSION << std::endl;
    return true;
}

std::int32_t compute_average(std::int32_t a, std::int32_t b){
    return (a + b) / 2; 
}