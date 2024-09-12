#include <cctype>
#include <string>
#include <unordered_map>

// Function to get the Soundex code for a given character
char getSoundexCode(char c, const std::unordered_map<char, char>& soundexMap) {
    char upperChar = toupper(c);
    auto it = soundexMap.find(upperChar);
    return it != soundexMap.end() ? it->second : '0';
}

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

    std::string soundex;
    soundex += toupper(name[0]);  // Start with the first letter
    char prevCode = soundexMap.at(soundex[0]);  // Get the initial code

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char upperChar = toupper(name[i]);
        char code = soundexMap.find(upperChar) != soundexMap.end() ? soundexMap.at(upperChar) : '0';

        // Append code if it's not '0' and different from the previous code
        soundex += (code != '0' && code != prevCode) ? code : "";
        prevCode = code;
    }

    soundex.append(4 - soundex.length(), '0');  // Pad with '0's if needed

    return soundex;
}
