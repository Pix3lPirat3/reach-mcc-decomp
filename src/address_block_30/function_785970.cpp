struct float_holder {
    unsigned char reserved0[8];
    float field_8;
};

struct source_state {
    unsigned char reserved0[0x18];
    float_holder* field_18;
};

struct lookup_key {
    unsigned char reserved0[0x10];
    void* field_10;
};

extern "C" long long function_785a30(void* state, void* key);

extern "C" float function_785970(source_state* state, lookup_key* key) {
    function_785a30((unsigned char*)state - 0x18, key->field_10);
    return state->field_18->field_8;
}
