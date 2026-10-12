struct parameter_block {
    void* field_0;
    void* field_8;
    void* field_10;
    void* field_18;
};

struct key_block {
    unsigned char reserved0[0x28];
    parameter_block* field_28;
};

extern "C" int dsa_missing_parameters_7ebb50(key_block* key) {
    parameter_block* parameters = key->field_28;
    if (parameters == 0)
        return 1;
    if (parameters->field_8 == 0)
        return 1;
    if (parameters->field_10 == 0)
        return 1;
    return parameters->field_18 == 0;
}
