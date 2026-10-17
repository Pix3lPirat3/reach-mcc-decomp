struct float_holder {
    unsigned char reserved0[8];
    float field_8;
};

struct source_state {
    unsigned char reserved0[0x20];
    float_holder* field_20;
};

struct lookup_key {
    unsigned char reserved0[0x20];
    void* field_20;
};

extern "C" long long function_785a30(void* state, void* key);

extern "C" float function_7859a0(source_state* state, lookup_key* key) {
    function_785a30((unsigned char*)state - 0x10, key->field_20);
    return state->field_20->field_8;
}
