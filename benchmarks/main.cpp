#include <random>

#include "celero/Celero.h"

CELERO_MAIN

std::random_device randomDevice;
std::uniform_int_distribution<int> uniformDistribution(0, 1024);

BASELINE(BenchmarkRandomGenerator, Test1, 10, 100000){

    celero::DoNotOptimizeAway(static_cast<float>(sin(uniformDistribution(randomDevice))));
}