struct record {
    char reserved0[4];
    unsigned char value;
};

extern "C" int function_132fd8(int value);

extern "C" unsigned char function_1f07a8(record* self, int value) {
    long long index = function_132fd8(value);
    if ((unsigned char)((char)index + 4) > 0x23)
        return (unsigned char)index;
    self->value = (char)index;
    return (unsigned char)index;
}
