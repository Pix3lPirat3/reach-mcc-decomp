struct source {
    char reserved0[4];
    short field_4;
};

extern "C" long long function_2acd30(char* target);

extern "C" source* function_2ff4c8(source* object) {
    object->field_4 = 0;
    function_2acd30((char*)object + 0x48);
    return object;
}
