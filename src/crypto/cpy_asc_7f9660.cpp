extern "C" int cpy_asc_7f9660(char value, char** cursor) {
    **cursor = value;
    *cursor = *cursor + 1;
    return 1;
}
