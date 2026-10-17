struct small_value {
    unsigned char reserved0[3];
    unsigned char value;
};

extern "C" int function_e0250(small_value* object, unsigned char input) {
    int result = input > 0x1F ? 1 : input;
    object->value = (char)result;
    return result;
}
