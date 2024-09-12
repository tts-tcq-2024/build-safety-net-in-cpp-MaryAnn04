#include <gtest/gtest.h>
#include "Soundex.h"

// Define a struct for test cases
struct SoundexTestCase {
    std::string input;
    std::string expectedOutput;
};

// Create a test fixture class with parameterized tests
class SoundexTest : public ::testing::TestWithParam<SoundexTestCase> {};

// Test case for handling empty strings
TEST_P(SoundexTest, HandlesEmptyString) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
    EmptyStringTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"", ""}
    )
);

// Test case for handling single character inputs
TEST_P(SoundexTest, HandlesSingleCharacter) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
    SingleCharacterTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"A", "A000"},
        SoundexTestCase{"R", "R000"}
    )
);

// Test case for handling strings with vowels
TEST_P(SoundexTest, HandlesVowels) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
    VowelTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"AEIOU", "A000"}
    )
);

// Test case for handling mixed strings
TEST_P(SoundexTest, HandlesMixedString) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
    MixedStringTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"ALEXANDER", "A425"}
    )
);

// Test case for handling ignored consonants
TEST_P(SoundexTest, HandlesIgnoredConsonants) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
    IgnoredConsonantsTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"HWY", "H000"}
    )
);

// Test case for handling repeated characters
TEST_P(SoundexTest, HandlesRepeatedCharacters) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
    RepeatedCharactersTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"BUTTERFLY", "B361"},
        SoundexTestCase{"Tomorrow", "T560"}
    )
);

// Test case for handling same case characters
TEST_P(SoundexTest, HandlesSameCaseCharacters) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
    SameCaseCharactersTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"MANGO", "M200"},
        SoundexTestCase{"JACK", "J000"}
    )
);

// Test case for handling special characters
TEST_P(SoundexTest, HandlesSpecialCharacters) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
    SpecialCharactersTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"RITA@", "R300"}
    )
);

// Test case for handling numeric inputs
TEST_P(SoundexTest, HandlesNumerics) {
    SoundexTestCase testCase = GetParam();
    EXPECT_EQ(generateSoundex(testCase.input), testCase.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
    NumericTests,
    SoundexTest,
    ::testing::Values(
        SoundexTestCase{"SITA12", "S300"}
    )
);
