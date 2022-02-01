#include "ns4.cpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(ns4) {
    function("encode", &ns4::encode);
    function("decode", &ns4::decode);
}

int main() {
}