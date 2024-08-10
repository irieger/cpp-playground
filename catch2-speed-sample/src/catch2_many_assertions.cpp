#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>

#include <cstdint>
#include <vector>

constexpr size_t SAMPLE_SIZE {3 * 20 * 1024 * 1024};
constexpr int32_t DELTA {20};

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
        CHECK(static_cast<int32_t>(values_ref[idx]) - static_cast<int32_t>(values_comp[idx]) << DELTA);
    }
}
