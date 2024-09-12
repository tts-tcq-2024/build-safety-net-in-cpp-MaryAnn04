#include <gtest/gtest.h>
#include "Soundex.h"

struct SoundexTestCase {
    std::string input;
    std::string expectedOutput;
};

class SoundexTest : public ::testing::TestWithParam<SoundexTestCase> {};

TEST(SoundexTest, EmptyString_ReturnsEmptyString) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST(
    SoundexTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"", ""}
       
    )
);

TEST(SoundexTest, SingleCharacter_ReturnsPaddedString) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST(
    SoundexTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"A", "A000"},
        SoundexTestCase{"R", "R000"}
    )
);


TEST(SoundexTest, VowelsAndIgnoredCharacters_ReturnsPaddedString) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST(
    SoundexTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"AEIOU", "A000"},
        SoundexTestCase{"HWY", "H000"}
    )
);

TEST(SoundexTest, MixedString_ReturnsSoundexCode) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST(
    SoundexTests,
    SoundexTest,
    ::testing::Values(
       
        SoundexTestCase{"ALEXANDER", "A425"},
        SoundexTestCase{"MANGO", "M200"},
        SoundexTestCase{"JACK", "J000"}
    )
);
TEST(SoundexTest, StringWithRepeatedCharacters_ReturnsStringWithKeyValuesIgnoringRepeatedKeyValues) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST(
    SoundexTests,
    SoundexTest,
    ::testing::Values(
    
        SoundexTestCase{"BUTTERFLY", "B361"},
        SoundexTestCase{"Tomorrow", "T560"}
    )
);

TEST(SoundexTest, StringWithSpecialCharacters_ReturnsSoundexCode) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST(
    SoundexTests,
    SoundexTest,
    ::testing::Values(

        SoundexTestCase{"RITA@", "R300"},
        SoundexTestCase{"SITA12", "S300"}
    )
);
