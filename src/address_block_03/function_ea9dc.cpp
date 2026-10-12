struct small_value {
    unsigned char reserved0[0x741];
    unsigned char value;
};

extern "C" int function_ea9dc(small_value* object, unsigned char input) {
    int result = input > 0xA ? 4 : input;
    object->value = (char)result;
    return result;
}
