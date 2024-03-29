﻿#include "ns4.h"
#include <random>
#include <unordered_map>

namespace ns4 {
void nya(std::wstring &s, int which) {
    static const std::wstring nd[]{L"喵", L"喵呜"};
    s += nd[which];
    s += L'。';
    s += L' ';
}

std::wstring encode(const std::string &data) {
    static std::random_device r;
    static std::default_random_engine e(r());
    static const std::wstring dict = L"̴̵̶̷̸̡̢̧̨̛̖̗̘̙̜̝̞̟̠̣̤̥̦̩̪̫̬̭̮̯̰̱̲̳̹̺̻̼͇͈͉͍͎̀́̂̃̄̅̆̇̈̉̊̋̌̍̎̏̐̑̒̓̔̽̾̿̀́͂̓̈́͆͊͋͌̕̚ͅ͏͓͔͕͖͙͚͐͑͒͗͛ͣͤͥͦͧͨͩͪͫͬͭͮͯ͘͜͟͢͝͞͠͡็่้๊๋์ํ๎҃҄҅҆҇҈҉ًٌٍؘَؙُؚِّْٰ֑֖֛֢֣֤֥֦֧֪ٕٖٜٟۣ֚֭֮֒֓֔֕֗֘֙֜֝֞֟֠֡֨֩֫֬֯ؐؑؒؓؔؕؖؗٓٔٗ٘ٙٚٛٝٞۖۗۘۙۚۛۜ۟۠ۡۢۤۦ۪ۭܱܴܷܸܹܻܼܾ݂݄݆݈ۧۨ۫۬ܰܲܳܵܶܺܽܿ݀݁݃݅݇݉݊ަާިީުޫެޭޮޯްິີຶືຸູົ";
    std::wstring s;
    int j = 0;
    bool flag = true;
    std::uniform_int_distribution<int> d;
    using p = decltype(d)::param_type;
    for (auto b: data) {
        s += dict[static_cast<uint8_t>(b)];
        if (d(e, p{1, 10 - j}) == 1) {
            nya(s, d(e, p{0, 1}));
            j = 0;
            flag = false;
        } else ++j;
    }
    if (flag) nya(s, d(e, p{0, 1}));
    return s;
}

std::string decode(const std::wstring &m) {
    const std::unordered_map<wchar_t, uint8_t> rdict = {
        {L'̀', 0},
        {L'́', 1},
        {L'̂', 2},
        {L'̃', 3},
        {L'̄', 4},
        {L'̅', 5},
        {L'̆', 6},
        {L'̇', 7},
        {L'̈', 8},
        {L'̉', 9},
        {L'̊', 10},
        {L'̋', 11},
        {L'̌', 12},
        {L'̍', 13},
        {L'̎', 14},
        {L'̏', 15},
        {L'̐', 16},
        {L'̑', 17},
        {L'̒', 18},
        {L'̓', 19},
        {L'̔', 20},
        {L'̕', 21},
        {L'̖', 22},
        {L'̗', 23},
        {L'̘', 24},
        {L'̙', 25},
        {L'̚', 26},
        {L'̛', 27},
        {L'̜', 28},
        {L'̝', 29},
        {L'̞', 30},
        {L'̟', 31},
        {L'̠', 32},
        {L'̡', 33},
        {L'̢', 34},
        {L'̣', 35},
        {L'̤', 36},
        {L'̥', 37},
        {L'̦', 38},
        {L'̧', 39},
        {L'̨', 40},
        {L'̩', 41},
        {L'̪', 42},
        {L'̫', 43},
        {L'̬', 44},
        {L'̭', 45},
        {L'̮', 46},
        {L'̯', 47},
        {L'̰', 48},
        {L'̱', 49},
        {L'̲', 50},
        {L'̳', 51},
        {L'̴', 52},
        {L'̵', 53},
        {L'̶', 54},
        {L'̷', 55},
        {L'̸', 56},
        {L'̹', 57},
        {L'̺', 58},
        {L'̻', 59},
        {L'̼', 60},
        {L'̽', 61},
        {L'̾', 62},
        {L'̿', 63},
        {L'̀', 64},
        {L'́', 65},
        {L'͂', 66},
        {L'̓', 67},
        {L'̈́', 68},
        {L'ͅ', 69},
        {L'͆', 70},
        {L'͇', 71},
        {L'͈', 72},
        {L'͉', 73},
        {L'͊', 74},
        {L'͋', 75},
        {L'͌', 76},
        {L'͍', 77},
        {L'͎', 78},
        {L'͏', 79},
        {L'͐', 80},
        {L'͑', 81},
        {L'͒', 82},
        {L'͓', 83},
        {L'͔', 84},
        {L'͕', 85},
        {L'͖', 86},
        {L'͗', 87},
        {L'͘', 88},
        {L'͙', 89},
        {L'͚', 90},
        {L'͛', 91},
        {L'͜', 92},
        {L'͝', 93},
        {L'͞', 94},
        {L'͟', 95},
        {L'͠', 96},
        {L'͡', 97},
        {L'͢', 98},
        {L'ͣ', 99},
        {L'ͤ', 100},
        {L'ͥ', 101},
        {L'ͦ', 102},
        {L'ͧ', 103},
        {L'ͨ', 104},
        {L'ͩ', 105},
        {L'ͪ', 106},
        {L'ͫ', 107},
        {L'ͬ', 108},
        {L'ͭ', 109},
        {L'ͮ', 110},
        {L'ͯ', 111},
        {L'็', 112},
        {L'่', 113},
        {L'้', 114},
        {L'๊', 115},
        {L'๋', 116},
        {L'์', 117},
        {L'ํ', 118},
        {L'๎', 119},
        {L'҃', 120},
        {L'҄', 121},
        {L'҅', 122},
        {L'҆', 123},
        {L'҇', 124},
        {L'҈', 125},
        {L'҉', 126},
        {L'֑', 127},
        {L'֒', 128},
        {L'֓', 129},
        {L'֔', 130},
        {L'֕', 131},
        {L'֖', 132},
        {L'֗', 133},
        {L'֘', 134},
        {L'֙', 135},
        {L'֚', 136},
        {L'֛', 137},
        {L'֜', 138},
        {L'֝', 139},
        {L'֞', 140},
        {L'֟', 141},
        {L'֠', 142},
        {L'֡', 143},
        {L'֢', 144},
        {L'֣', 145},
        {L'֤', 146},
        {L'֥', 147},
        {L'֦', 148},
        {L'֧', 149},
        {L'֨', 150},
        {L'֩', 151},
        {L'֪', 152},
        {L'֫', 153},
        {L'֬', 154},
        {L'֭', 155},
        {L'֮', 156},
        {L'֯', 157},
        {L'ؐ', 158},
        {L'ؑ', 159},
        {L'ؒ', 160},
        {L'ؓ', 161},
        {L'ؔ', 162},
        {L'ؕ', 163},
        {L'ؖ', 164},
        {L'ؗ', 165},
        {L'ؘ', 166},
        {L'ؙ', 167},
        {L'ؚ', 168},
        {L'ً', 169},
        {L'ٌ', 170},
        {L'ٍ', 171},
        {L'َ', 172},
        {L'ُ', 173},
        {L'ِ', 174},
        {L'ّ', 175},
        {L'ْ', 176},
        {L'ٓ', 177},
        {L'ٔ', 178},
        {L'ٕ', 179},
        {L'ٖ', 180},
        {L'ٗ', 181},
        {L'٘', 182},
        {L'ٙ', 183},
        {L'ٚ', 184},
        {L'ٛ', 185},
        {L'ٜ', 186},
        {L'ٝ', 187},
        {L'ٞ', 188},
        {L'ٟ', 189},
        {L'ٰ', 190},
        {L'ۖ', 191},
        {L'ۗ', 192},
        {L'ۘ', 193},
        {L'ۙ', 194},
        {L'ۚ', 195},
        {L'ۛ', 196},
        {L'ۜ', 197},
        {L'۟', 198},
        {L'۠', 199},
        {L'ۡ', 200},
        {L'ۢ', 201},
        {L'ۣ', 202},
        {L'ۤ', 203},
        {L'ۦ', 204},
        {L'ۧ', 205},
        {L'ۨ', 206},
        {L'۪', 207},
        {L'۫', 208},
        {L'۬', 209},
        {L'ۭ', 210},
        {L'ܰ', 211},
        {L'ܱ', 212},
        {L'ܲ', 213},
        {L'ܳ', 214},
        {L'ܴ', 215},
        {L'ܵ', 216},
        {L'ܶ', 217},
        {L'ܷ', 218},
        {L'ܸ', 219},
        {L'ܹ', 220},
        {L'ܺ', 221},
        {L'ܻ', 222},
        {L'ܼ', 223},
        {L'ܽ', 224},
        {L'ܾ', 225},
        {L'ܿ', 226},
        {L'݀', 227},
        {L'݁', 228},
        {L'݂', 229},
        {L'݃', 230},
        {L'݄', 231},
        {L'݅', 232},
        {L'݆', 233},
        {L'݇', 234},
        {L'݈', 235},
        {L'݉', 236},
        {L'݊', 237},
        {L'ަ', 238},
        {L'ާ', 239},
        {L'ި', 240},
        {L'ީ', 241},
        {L'ު', 242},
        {L'ޫ', 243},
        {L'ެ', 244},
        {L'ޭ', 245},
        {L'ޮ', 246},
        {L'ޯ', 247},
        {L'ް', 248},
        {L'ິ', 249},
        {L'ີ', 250},
        {L'ຶ', 251},
        {L'ື', 252},
        {L'ຸ', 253},
        {L'ູ', 254},
        {L'ົ', 255}
    };
    std::string data;
    for (auto b : m) {
        const auto it = rdict.find(b);
        if (it != rdict.end()) data += it->second;
    }
    return data;
}
}
