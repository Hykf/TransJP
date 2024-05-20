#include "TransJP.h"
#include <regex>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <codecvt>
#include <locale>

namespace transjp {

    TransJP::TransJP() {

        HIRAGANA_TO_ROMAJI_MAP = {
                {"あ", "a"}, {"い", "i"}, {"う", "u"}, {"え", "e"}, {"お", "o"},
                {"か", "ka"}, {"き", "ki"}, {"く", "ku"}, {"け", "ke"}, {"こ", "ko"},
                {"さ", "sa"}, {"し", "shi"}, {"す", "su"}, {"せ", "se"}, {"そ", "so"},
                {"た", "ta"}, {"ち", "chi"}, {"つ", "tsu"}, {"て", "te"}, {"と", "to"},
                {"な", "na"}, {"に", "ni"}, {"ぬ", "nu"}, {"ね", "ne"}, {"の", "no"},
                {"は", "ha"}, {"ひ", "hi"}, {"ふ", "fu"}, {"へ", "he"}, {"ほ", "ho"},
                {"ま", "ma"}, {"み", "mi"}, {"む", "mu"}, {"め", "me"}, {"も", "mo"},
                {"や", "ya"}, {"ゆ", "yu"}, {"よ", "yo"},
                {"ら", "ra"}, {"り", "ri"}, {"る", "ru"}, {"れ", "re"}, {"ろ", "ro"},
                {"わ", "wa"}, {"を", "wo"}, {"ん", "n"},
                {"が", "ga"}, {"ぎ", "gi"}, {"ぐ", "gu"}, {"げ", "ge"}, {"ご", "go"},
                {"ざ", "za"}, {"じ", "ji"}, {"ず", "zu"}, {"ぜ", "ze"}, {"ぞ", "zo"},
                {"だ", "da"}, {"ぢ", "ji"}, {"づ", "zu"}, {"で", "de"}, {"ど", "do"},
                {"ぱ", "pa"}, {"ぴ", "pi"}, {"ぷ", "pu"}, {"ぺ", "pe"}, {"ぽ", "po"},
                {"ば", "ba"}, {"び", "bi"}, {"ぶ", "bu"}, {"べ", "be"}, {"ぼ", "bo"},

                {"きゃ", "kya"}, {"きゅ", "kyu"}, {"きょ", "kyo"},
                {"しゃ", "sha"}, {"しゅ", "shu"}, {"しょ", "sho"},
                {"ちゃ", "cha"}, {"ちゅ", "chu"}, {"ちょ", "cho"},
                {"にゃ", "nya"}, {"にゅ", "nyu"}, {"にょ", "nyo"},
                {"ひゃ", "hya"}, {"ひゅ", "hyu"}, {"ひょ", "hyo"},
                {"みゃ", "mya"}, {"みゅ", "myu"}, {"みょ", "myo"},
                {"りゃ", "rya"}, {"りゅ", "ryu"}, {"りょ", "ryo"},
                {"ぎゃ", "gya"}, {"ぎゅ", "gyu"}, {"ぎょ", "gyo"},
                {"じゃ", "ja"}, {"じゅ", "ju"}, {"じょ", "jo"},
                {"びゃ", "bya"}, {"びゅ", "byu"}, {"びょ", "byo"},
                {"ぴゃ", "pya"}, {"ぴゅ", "pyu"}, {"ぴょ", "pyo"}
        };

        // Katakana to Romaji map
        KATAKANA_TO_ROMAJI_MAP = {
                {"ア", "a"}, {"イ", "i"}, {"ウ", "u"}, {"エ", "e"}, {"オ", "o"},
                {"カ", "ka"}, {"キ", "ki"}, {"ク", "ku"}, {"ケ", "ke"}, {"コ", "ko"},
                {"サ", "sa"}, {"シ", "shi"}, {"ス", "su"}, {"セ", "se"}, {"ソ", "so"},
                {"タ", "ta"}, {"チ", "chi"}, {"ツ", "tsu"}, {"テ", "te"}, {"ト", "to"},
                {"ナ", "na"}, {"ニ", "ni"}, {"ヌ", "nu"}, {"ネ", "ne"}, {"ノ", "no"},
                {"ハ", "ha"}, {"ヒ", "hi"}, {"フ", "fu"}, {"ヘ", "he"}, {"ホ", "ho"},
                {"マ", "ma"}, {"ミ", "mi"}, {"ム", "mu"}, {"メ", "me"}, {"モ", "mo"},
                {"ヤ", "ya"}, {"ユ", "yu"}, {"ヨ", "yo"},
                {"ラ", "ra"}, {"リ", "ri"}, {"ル", "ru"}, {"レ", "re"}, {"ロ", "ro"},
                {"ワ", "wa"}, {"ヲ", "wo"}, {"ン", "n"},

                {"ガ", "ga"}, {"ギ", "gi"}, {"グ", "gu"}, {"ゲ", "ge"}, {"ゴ", "go"},
                {"ザ", "za"}, {"ジ", "ji"}, {"ズ", "zu"}, {"ゼ", "ze"}, {"ゾ", "zo"},
                {"ダ", "da"}, {"ヂ", "ji"}, {"ヅ", "zu"}, {"デ", "de"}, {"ド", "do"},
                {"パ", "pa"}, {"ピ", "pi"}, {"プ", "pu"}, {"ペ", "pe"}, {"ポ", "po"},
                {"バ", "ba"}, {"ビ", "bi"}, {"ブ", "bu"}, {"ベ", "be"}, {"ボ", "bo"},

                {"キャ", "kya"}, {"キュ", "kyu"}, {"キョ", "kyo"},
                {"シャ", "sha"}, {"シュ", "shu"}, {"ショ", "sho"},
                {"チャ", "cha"}, {"チュ", "chu"}, {"チョ", "cho"},
                {"ニャ", "nya"}, {"ニュ", "nyu"}, {"ニョ", "nyo"},
                {"ヒャ", "hya"}, {"ヒュ", "hyu"}, {"ヒョ", "hyo"},
                {"ミャ", "mya"}, {"ミュ", "myu"}, {"ミョ", "myo"},
                {"リャ", "rya"}, {"リュ", "ryu"}, {"リョ", "ryo"},
                {"ギャ", "gya"}, {"ギュ", "gyu"}, {"ギョ", "gyo"},
                {"ジャ", "ja"}, {"ジュ", "ju"}, {"ジョ", "jo"},
                {"ビャ", "bya"}, {"ビュ", "byu"}, {"ビョ", "byo"},
                {"ピャ", "pya"}, {"ピュ", "pyu"}, {"ピョ", "pyo"},
                {"ー", "-"}, {"ッ", ""}
        };

        ROMAJI_TO_HIRAGANA_MAP = ReverseMap(HIRAGANA_TO_ROMAJI_MAP);
        ROMAJI_TO_KATAKANA_MAP = ReverseMap(KATAKANA_TO_ROMAJI_MAP);

    }



    std::string TransJP::to_katakana(std::string str) {
        std::string result;
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);

        size_t i = 0;
        while (i < str.size()) {

            std::string combined_str;
            bool found = false;

            for (int len = 3; len > 0; --len) {

                if (i + len <= str.size()) {

                    combined_str = str.substr(i, len);
                    auto it = ROMAJI_TO_KATAKANA_MAP.find(combined_str);
                    if (it != ROMAJI_TO_KATAKANA_MAP.end()) {

                        result += it->second;
                        i += len;
                        found = true;
                        break;

                    }

                }

            }

            if (!found) {
                result += "ッ"; // TODO ogarnac kreske przy przedluzeniu
                ++i;

            }

        }

        return result;

    }

    std::string TransJP::to_hiragana(std::string str) {
        std::string result;
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);

        size_t i = 0;

        while (i < str.size()) {

            std::string combined_str;
            bool found = false;

            for (int len = 3; len > 0; --len) {

                if (i + len <= str.size()) {
                    combined_str = str.substr(i, len);

                    auto it = ROMAJI_TO_HIRAGANA_MAP.find(combined_str);

                    if (it != ROMAJI_TO_HIRAGANA_MAP.end()) {

                        result += it->second;
                        i += len;
                        found = true;
                        break;

                    }

                }

            }

            if (!found) {
                result += "っ";
                ++i;
            }

        }

        return result;

    }

    std::string TransJP::to_roma(std::string str,WritingMode mode) {

        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wstr = converter.from_bytes(str);

        std::unordered_map<std::string, std::string> sourceMap = (mode == WritingMode::HIRAGANA)? HIRAGANA_TO_ROMAJI_MAP : KATAKANA_TO_ROMAJI_MAP;

        std::wstring wresult;

        for (size_t i = 0; i < wstr.length(); ++i) {
            std::wstring combined_str;
            if (i < wstr.length() - 1) {
                combined_str = wstr.substr(i, 2);
                auto it = sourceMap.find(converter.to_bytes(combined_str));
                if (it != sourceMap.end()) {
                    wresult += converter.from_bytes(it->second);
                    ++i; // Pomijamy następny znak
                    continue;
                }
            }

            combined_str = wstr.substr(i, 1);
            auto it = sourceMap.find(converter.to_bytes(combined_str));
            if (it != sourceMap.end()) {
                wresult += converter.from_bytes(it->second);
            } else {
                wresult += combined_str; // Dodaj oryginalny znak jeśli nie znaleziono w mapie
            }
        }

        return converter.to_bytes(wresult);
    }



    std::unordered_map<std::string, std::string> TransJP::ReverseMap(std::unordered_map<std::string, std::string> mapToRevers) {
        std::unordered_map<std::string, std::string> mapToReturn;

        for(auto i = mapToRevers.begin(); i != mapToRevers.end(); i++){
            mapToReturn[i->second] = i->first;
        }

        return mapToReturn;

    }

} // namespace transjp