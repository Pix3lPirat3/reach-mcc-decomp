extern "C" char function_8790e0(char* dest, const char* source) {
    char c;
    do {
        c = *source;
        *dest = c;
        ++source;
        ++dest;
    } while (c != 0);
    return c;
}
