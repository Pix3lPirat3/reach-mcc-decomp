extern "C" char function_5c7b0();

extern "C" unsigned int* function_303880(void*, unsigned int* result) {
    unsigned int mask = function_5c7b0() != 0 ? 0xfff801feu : 0u;
    *result = mask + 0x8013a;
    return result;
}
