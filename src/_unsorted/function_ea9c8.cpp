struct small_value {
    unsigned char reserved0[0x740];
    unsigned char value;
};

extern "C" int function_ea9c8(small_value* object, unsigned char input) {
    int result = input > 0xC8 ? 0 : input;
    object->value = (char)result;
    return result;
}
