struct counted {
    unsigned char reserved0[0x24];
    int field_24;
};

struct source_state {
    unsigned char reserved0[0x30];
    counted* field_30;
};

extern "C" char* function_785bb0(source_state* state, char* result) {
    *result = state->field_30->field_24 > 0;
    return result;
}
