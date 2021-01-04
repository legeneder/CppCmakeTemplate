#pragma once

#include <iostream>
#include <stdio.h>

#include "linalg.h"
#include "boost/version.hpp"

/**
 * @brief This function prints hello world.
 * 
 */
bool cout_hello_world();

linalg::aliases::float3 print_linalg_vector();

bool print_hello_world();

bool print_boost_version();

std::int32_t compute_average(std::int32_t a, std::int32_t b);