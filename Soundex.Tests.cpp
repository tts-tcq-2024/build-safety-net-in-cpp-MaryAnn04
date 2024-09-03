#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("R"), "R000");
}
TEST(SoundexTest, HandlesVowels) {
    EXPECT_EQ(generateSoundex("AEIOU"), "A000");
}
TEST(SoundexTest, HandlesMixedString) {
    EXPECT_EQ(generateSoundex("ALEXANDER"), "A425");
}
TEST(SoundexTest, HandlesIgnoredConsonents) {
    EXPECT_EQ(generateSoundex("HWY"), "H000");
}
TEST(SoundexTest, HandlesRepeatedCharacter) {
    EXPECT_EQ(generateSoundex("BUTTERFLY"), "B361");
    EXPECT_EQ(generateSoundex("Tomorrow"), "T560");
}
TEST(SoundexTest, HandlesSameCaseCharacters) {
    EXPECT_EQ(generateSoundex("MANGO"), "M200");
    EXPECT_EQ(generateSoundex("JACK"), "J000");
}
TEST(SoundexTest, HandlesSpecialCharacters) {
    EXPECT_EQ(generateSoundex("RITA@"), "R300");
}
TEST(SoundexTest, HandlesNumerics) {
EXPECT_EQ(generateSoundex("SITA12"), "S300");
}
