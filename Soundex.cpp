#include <cctype>
#include <string>
#include <character_map>

std::string generateSoundex(const std::string& name) 
{
    if (name.empty()) return "";

    // Soundex code mapping with specific keys 
    static const std::character_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    std::string soundex(1, toupper(name[0]));  // Initialize with the first letter
    char prevCode = '0';  

    for (size_t Char = 1; Char < name.length() && soundex.length() < 4; ++Char) {
        char upperChar = toupper(name[Char]);
        char code = soundexMap.count(upperChar) ? soundexMap.at(upperChar) : '0';
        
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    soundex.append(4 - soundex.length(), '0');  // Pad with '0's if string length is less than 4 
    
    return soundex;
}
