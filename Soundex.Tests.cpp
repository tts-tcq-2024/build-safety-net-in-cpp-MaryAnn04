#include <gtest/gtest.h>
#include "Soundex.h"

struct SoundexTestCase {
    std::string input;
    std::string expectedOutput;
};

class SoundexTest : public ::testing::TestWithParam<SoundexTestCase> {};

TEST_P(SoundexTest, EmptyString_ReturnsEmptyString) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_P(
    SoundexTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"", ""}
       
    )
);

TEST_P(SoundexTest, SingleCharacter_ReturnsPaddedString) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_P(
    SoundexTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"A", "A000"},
        SoundexTestCase{"R", "R000"}
    )
);

