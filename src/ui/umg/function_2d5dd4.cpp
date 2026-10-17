struct value_in {
    unsigned char reserved0[8];
    unsigned char value;
};

extern "C" long long c_cui_widget__set_enabled_2d4e64(void* widget, unsigned char enabled);

extern "C" char function_2d5dd4(void* widget, void*, value_in* in) {
    c_cui_widget__set_enabled_2d4e64(widget, in->value);
    return 1;
}
