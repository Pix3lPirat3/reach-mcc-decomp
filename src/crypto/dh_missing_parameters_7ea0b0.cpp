struct parameter_block {
    void* field_0;
    void* field_8;
    void* field_10;
};

struct key_block {
    unsigned char reserved0[0x28];
    parameter_block* field_28;
};

extern "C" int dh_missing_parameters_7ea0b0(key_block* key) {
    parameter_block* parameters = key->field_28;
    if (parameters == 0)
        return 1;
    if (parameters->field_8 == 0)
        return 1;
    return parameters->field_10 == 0;
}
