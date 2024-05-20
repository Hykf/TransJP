#include "TransJP.h"
#include <iostream>

int main() {

    // TODO 1. kombinacje typu VO w katakanie ヴォドカ
    // TODO 2. w katakanie dlugie znaki ー　i male tsu

    transjp::TransJP transjp;

    std::cout<< "ひらがな: " << transjp.to_roma("ひらがな",transjp::TransJP::HIRAGANA)  << std::endl;
    std::cout<< "カタカナ: " << transjp.to_roma("カタカナ",transjp::TransJP::KATAKANA)  << std::endl;

    auto x = "zasshi";

    std::cout <<"TO hiragana: " << transjp.to_hiragana(x)  << std::endl;
    std::cout <<"TO katakana: " << transjp.to_katakana(x)  << std::endl;

    return 0;
}