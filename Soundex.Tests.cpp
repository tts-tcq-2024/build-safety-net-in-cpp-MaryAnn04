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
TEST(SoundexTest, Handleslongstring) {
    EXPECT_EQ(generateSoundex("ALEXANDER"), "A425");
}
TEST(SoundexTest, HandlesIgnoredConsonents) {
    EXPECT_EQ(generateSoundex("HWY"), "H000");
}
TEST(SoundexTest, HandlesRepeatedCharacter) {
    EXPECT_EQ(generateSoundex("BUTTERFLY"), "B336");
}
