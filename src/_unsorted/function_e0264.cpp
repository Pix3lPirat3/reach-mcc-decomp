struct small_value {
    unsigned char reserved0[1];
    unsigned char value;
};

extern "C" int function_e0264(small_value* object, unsigned char input) {
    int result = input > 5 ? 2 : input;
    object->value = (char)result;
    return result;
}
