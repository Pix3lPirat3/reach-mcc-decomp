struct property_value {
    unsigned char reserved0[8];
    unsigned char flag;
};

extern "C" void* c_cui_widget__set_visible_2d4dcc(void* widget, unsigned char visible);

extern "C" char cui_set_scalar_property_by_value_2d5dac_2d5dac(void* widget, void*, const property_value* value) {
    c_cui_widget__set_visible_2d4dcc(widget, value->flag);
    return 1;
}
