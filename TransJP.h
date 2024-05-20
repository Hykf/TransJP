#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#ifndef TRANSJP_TRANSJP_H
#define TRANSJP_TRANSJP_H

namespace transjp {
    class TransJP {
    public:

        enum WritingMode {
            HIRAGANA,
            KATAKANA
        };

        TransJP();

        std::unordered_map<std::string, std::string> HIRAGANA_TO_ROMAJI_MAP;
        std::unordered_map<std::string, std::string> KATAKANA_TO_ROMAJI_MAP;
        std::unordered_map<std::string, std::string> ROMAJI_TO_HIRAGANA_MAP;
        std::unordered_map<std::string, std::string> ROMAJI_TO_KATAKANA_MAP;


        std::string to_katakana(std::string str);
        std::string to_hiragana(std::string str);
        std::string to_roma(std::string str,WritingMode mode);
        std::unordered_map<std::string, std::string> ReverseMap(std::unordered_map<std::string, std::string> mapToRevers);
        bool is_consonant(char c);
        bool is_vowel(char c);


        };

} // transjp

#endif
