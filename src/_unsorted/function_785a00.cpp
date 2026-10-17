struct float_holder {
    unsigned char reserved0[8];
    float field_8;
};

struct source_state {
    unsigned char reserved0[0x30];
    float_holder* field_30;
};

struct lookup_key {
    unsigned char reserved0[0x20];
    void* field_20;
};

extern "C" long long function_785a30(source_state* state, void* key);

extern "C" float function_785a00(source_state* state, lookup_key* key) {
    function_785a30(state, key->field_20);
    return state->field_30->field_8;
}
