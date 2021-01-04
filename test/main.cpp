

#include "my_lib.h"
#include "linalg.h"
#include "gtest/gtest.h"

TEST(TestSuite_MyLib, Test_ComputeAverage){
    std::int32_t valueA = 12;
    std::int32_t valueB = 20;
    std::int32_t expectedResult = 16;

    std::int32_t result = compute_average(valueA, valueB);
    std::int32_t result2 = compute_average(valueB, valueA);
    ASSERT_EQ(expectedResult, result);
    ASSERT_EQ(expectedResult, result2);
}

TEST(TestSuite_MyLib, Test_Prints){
    bool expected_result = true;
    bool printResult = print_hello_world();
    bool coutResult = cout_hello_world();
    bool boostResult = print_boost_version();

    ASSERT_EQ(expected_result, printResult);
    ASSERT_EQ(expected_result, coutResult);
    ASSERT_EQ(expected_result, boostResult);
}

TEST(TestSuite_MyLib, Test_Vector){
    linalg::aliases::float3 expected_result = {1,2,3};
    linalg::aliases::float3 result = print_linalg_vector();

    for(int i = 0; i < 3; ++i){
        ASSERT_EQ(expected_result[i], result[i]);
    }

}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
