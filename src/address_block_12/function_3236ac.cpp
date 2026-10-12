struct input_block {
    unsigned char reserved0[0x98];
    unsigned int field_98;
};

struct output_block {
    unsigned char reserved0[8];
    char value;
};

extern "C" long long c_player_muting_component__set_player_muted_323404(input_block* input, int index, char value);

extern "C" char function_3236ac(input_block* input, long long, output_block* output) {
    unsigned int index = input->field_98;
    if (index > 3)
        return 1;
    c_player_muting_component__set_player_muted_323404(input, static_cast<int>(index), output->value);
    return 1;
}
