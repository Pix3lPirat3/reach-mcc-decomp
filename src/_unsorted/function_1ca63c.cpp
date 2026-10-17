struct id_list {
    char reserved0[0x10];
    int ids[16];
    int count;
};

extern "C" char* function_1ca63c(id_list* list, char* result, int id) {
    *result = 1;
    if (id == 0x2FF8C16F || id == (int)0xAD345A23 || id == (int)0xAD45D441 || id == (int)0xDBC34901 ||
        id == (int)0xF0234345 || id == 0x11FCE585 || id == 0x297C7244 || (unsigned int)(id - 0x2FF8C16C) <= 1 ||
        id == 0x34DF5494 || id == 0x38F1276D || id == 0x578CEF50 || id == 0x5FE59C18 || id == 0x6E8D163B ||
        id == 0x758787BE || id == 0x7910923C)
        *result = 0;
    long long count = list->count;
    if (count <= 0)
        return result;
    long long index = 0;
    const int* entry = list->ids;
    while (*entry != id) {
        ++index;
        ++entry;
        if (index < count)
            continue;
        return result;
    }
    *result = 0;
    return result;
}
