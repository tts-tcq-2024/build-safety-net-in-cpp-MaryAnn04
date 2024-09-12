#include <gtest/gtest.h>
#include "Soundex.h"

struct SoundexTestCase {
    std::string input;
    std::string expectedOutput;
};

class SoundexTest : public ::testing::TestWithParam<SoundexTestCase> {};

TEST_P(SoundexTest, HandlesVariousCases) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
    SoundexTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"", ""},
        SoundexTestCase{"A", "A000"},
        SoundexTestCase{"R", "R000"},
        SoundexTestCase{"AEIOU", "A000"},
        SoundexTestCase{"ALEXANDER", "A425"},
        SoundexTestCase{"HWY", "H000"},
        SoundexTestCase{"BUTTERFLY", "B361"},
        SoundexTestCase{"Tomorrow", "T560"},
        SoundexTestCase{"MANGO", "M200"},
        SoundexTestCase{"JACK", "J000"},
        SoundexTestCase{"RITA@", "R300"},
        SoundexTestCase{"SITA12", "S300"}
    )
);
