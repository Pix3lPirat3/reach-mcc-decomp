struct small_value {
    unsigned char reserved0[2];
    unsigned char value;
};

extern "C" int function_e023c(small_value* object, unsigned char input) {
    int result = input > 0x3C ? 8 : input;
    object->value = (char)result;
    return result;
}
