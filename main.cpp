#include "TransJP.h"
#include <iostream>

int main() {

    transjp::TransJP transjp;

    std::cout<< "ひらがな: " << transjp.to_roma("ひらがな",transjp::TransJP::HIRAGANA)  << std::endl;
    std::cout<< "カタカナ: " << transjp.to_roma("ヴォドカ",transjp::TransJP::KATAKANA)  << std::endl;

    std::cout <<"TO hiragana: " << transjp.to_hiragana("katakana")  << std::endl;
    std::cout <<"TO hiragana: " << transjp.to_hiragana("カタカナ")  << std::endl;

    std::cout <<"TO katakana: " << transjp.to_katakana("ひらがな")  << std::endl;
    std::cout <<"TO katakana: " << transjp.to_katakana("hiragana")  << std::endl;

    return 0;
}