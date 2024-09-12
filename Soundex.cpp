#include <cctype>
#include <string>
#include <unordered_map>

// Function to get the Soundex code for a given character
char getSoundexCode(char c, const std::unordered_map<char, char>& soundexMap) {
    char upperChar = toupper(c);
    return soundexMap.count(upperChar) ? soundexMap.at(upperChar) : '0';
}

// Function to append the Soundex code if it meets the criteria
void appendSoundexCode(std::string& soundex, char code, char& prevCode) {
    if (code != '0' && code != prevCode) {
        soundex += code;
        prevCode = code;
    }
}

// Function to pad the Soundex string to ensure it's 4 characters long
void padSoundex(std::string& soundex) {
    soundex.append(4 - soundex.length(), '0');
}

// Main function to generate the Soundex code
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    // Soundex code mapping
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    std::string soundex(1, toupper(name[0]));  // Initialize with the first letter
    char prevCode = '0';  // To handle the first character correctly

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i], soundexMap);
        appendSoundexCode(soundex, code, prevCode);
    }

    padSoundex(soundex);  // Pad with '0's if needed
    
    return soundex;
}
