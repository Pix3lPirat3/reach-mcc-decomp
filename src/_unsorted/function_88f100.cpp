struct destination {
    unsigned char reserved0[2];
    char field_2;
};

extern "C" long long function_8f8800(char* source, void* arg1, long long arg2);

extern "C" int function_88f100(char* source, destination* dest, void* arg1, long long arg2) {
    function_8f8800(source, arg1, arg2);
    unsigned char value = source[2];
    dest->field_2 = value;
    return value;
}
