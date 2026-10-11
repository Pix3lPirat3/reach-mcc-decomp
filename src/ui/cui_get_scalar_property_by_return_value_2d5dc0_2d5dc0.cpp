struct property_value {
    int kind;
    unsigned char reserved4[4];
    char flag;
};

extern "C" char cui_get_scalar_property_by_return_value_2d5dc0_2d5dc0(const unsigned char* widget, void*, property_value* value) {
    unsigned int flags = *(const unsigned int*)(widget + 0x70);
    value->kind = 0;
    value->flag = (char)(flags >> 2) & 1;
    return 1;
}
