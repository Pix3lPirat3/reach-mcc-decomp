struct placement {
    float value;
    unsigned char flag;
};

struct biped_state {
    unsigned char reserved0[0x70];
    placement place;
};

extern "C" void function_47d780(int unit_index, void * place);

extern "C" void function_4a09ec(int unit_index, biped_state* state) {
    return function_47d780(unit_index, &state->place);
}
