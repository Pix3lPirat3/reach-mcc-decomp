struct game_state_block {
    unsigned char reserved0[8];
    int field_8;
};

extern "C" void function_a0274(int region, int index);

extern "C" void function_27bf6c(game_state_block* block) {
    return function_a0274(3, block->field_8);
}
