#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    // Soundex code mapping using vectors of keys
    static const std::unordered_map<char, std::vector<char>> soundexMap = {
        {'1', {'B', 'F', 'P', 'V'}},
        {'2', {'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'}},
        {'3', {'D', 'T'}},
        {'4', {'L'}},
        {'5', {'M', 'N'}},
        {'6', {'R'}}
    };

    // Function to find the Soundex code for a given character
    auto getSoundexCode = [&](char ch) -> char {
        ch = toupper(ch);
        for (const auto& [code, chars] : soundexMap) {
            if (std::find(chars.begin(), chars.end(), ch) != chars.end()) {
                return code;
            }
        }
        return '0';  // Return '0' if no Soundex code is found for the character
    };

    std::string soundex(1, toupper(name[0]));  // Initialize with the first letter
    char prevCode = '0';  // To handle the first character correctly

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);

        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    soundex.append(4 - soundex.length(), '0');  // Pad with '0's if needed

    return soundex;
}

