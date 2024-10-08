#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>

#include <cmath>
#include <cstdint>
#include <vector>


using namespace Catch::Matchers;


constexpr size_t SAMPLE_SIZE {3 * 20 * 1024 * 1024};
constexpr int32_t DELTA {20};

// Switch this flag to run with every 65536th value failing or use false to succeed all checks
constexpr bool RUN_FAILURE_CASE {false};


TEST_CASE("SimpleTest")
{
    std::vector<uint16_t> values_ref(SAMPLE_SIZE);
    std::vector<uint16_t> values_comp(SAMPLE_SIZE);

    // This is just a placeholder where some image processing algorithm would be
    for (size_t idx = 0; idx < SAMPLE_SIZE; ++idx)
    {
        values_ref[idx]  = static_cast<uint16_t>(idx % 65535);
        values_comp[idx] = static_cast<uint16_t>((idx + 15) % 65535);
    }

    for (size_t idx = 0; idx < SAMPLE_SIZE; ++idx)
    {
        if constexpr (RUN_FAILURE_CASE)
        {
            CHECK(std::abs(static_cast<int32_t>(values_ref[idx]) - static_cast<int32_t>(values_comp[idx])) < DELTA);
        }
        else
        {
            CHECK(std::abs(static_cast<int32_t>(values_ref[idx]) - static_cast<int32_t>(values_comp[idx])));
        }
    }

    // Not really working for vectors & ints, right?
    // CHECK_THAT(values_comp, WithinAbs(values_ref, DELTA));
}
