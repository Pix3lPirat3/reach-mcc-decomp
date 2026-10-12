extern "C" float function_785bf0(void* state, void* key);

extern "C" char* function_785b80(void* state, char* result, void* key) {
    function_785bf0((unsigned char*)state - 8, key);
    *result = 1;
    return result;
}
